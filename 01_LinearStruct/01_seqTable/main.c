#include <stdio.h>

//结构声明
typedef int Element_t;

//定义顺序表的表头结构
typedef struct 
{
    Element_t *data; //数据区，存储表空间的首地址
    int pos;      //指向表空间中待插入位置的索引号
    int capacity;    //顺序表的最大容量，一旦超过这个容量，触发扩容操作
} SEQTable_t;

//函数接口的实现

//创建顺序表
SEQTable_t *createSeqTable(int n){
    SEQTable_t *table = malloc(sizeof(SEQTable_t)); //动态分配内存，用于存储SEQTable_t结构体
    if(table == NULL){
        printf("createSeqTable  malloc failed!\n");
        return NULL;
    }
    table->data = malloc(sizeof(Element_t) * n); //动态分配足够存储 n 个 Element_t 类型元素的内存空间。
    table->capacity = n;
    return table;
    if(table->data == NULL){
        printf("createSeqTable  malloc failed!\n");
        free(table);
        return NULL;
    }
    return table;
}; 

static void  enlargerSeqTable(SEQTable_t *table){
    //1.再申请一个更大的新空间
    Element_t *tmp = malloc(sizeof(Element_t) * (table->capacity * 2));//由于malloc的时间消耗，通常采用2倍扩容
    if(tmp == NULL){
        printf("enlargerSeqTable  malloc failed!\n");
        return -1; //失败
    }

    //2.把原来的数据复制到新空间
    //注意：这里使用了 memcpy 函数来复制内存内容,将 table->data 指向的内存区域中的数据复制到 tmp 指向的内存区域
    memcpy(tmp, table->data, sizeof(Element_t) * table->capacity);

    //3.释放原来的空间,让表头里的data指针指向新空间

    table->capacity *= 2; //扩容后容量翻倍
    free(table->data);
    table->data = tmp; 
    return 0;
}
//释放顺序表
void releaseSeqTable(SEQTable_t *table){
    if(table){
        if(table->data){
            free(table->data); //释放数据区内存
        }
        free(table); //释放表头结构体内存
    }
};

//尾插法插入元素
int pushbackSeqTable(SEQTable_t *table, Element_t value){
    //1.空间根本就不存在
    if(table == NULL || table->data == NULL){
        printf("table is NULL or table->data is NULL!\n");
        return -1; //失败  
    }

    //2.空间已满,再插入就溢出了，就应该扩容
      //先判断pos是否已经超过了容量，再判断enlargerTable返回值是否为非零值，如果是，则扩容失败
    if(table->pos >= table->capacity && enlargerTable(table)){
        return -1; //扩容失败
    };
}
void deleteSeqTable(SEQTable_t *table, Element_t value){

};
void showSeqTable(const SEQTable_t *table){
    printf("pos/capacity: %d/%d\n", table->pos, table->capacity);
    for(int i = 0; i < table->pos; i++){
        printf("%d ", table->data[i]);
    }
    printf("\n");
};
int findSeqTable(const SEQTable_t *table, Element_t value){

};

//main函数测试
int main() {
    SEQTable_t *table = createSeqTable(10);

    for(int i = 0; i < 10; i++){
        pushbackSeqTable(table, i+100);
    }
    showSeqTable(table);

    deleteSeqTable(table, 113);

    showSeqTable(table);
    return 0;
}