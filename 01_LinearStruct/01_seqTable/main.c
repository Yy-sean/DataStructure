#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    table->pos = 0; //初始化 pos 为 0，表示当前没有元素
    
    if(table->data == NULL){
        printf("createSeqTable  malloc failed!\n");
        free(table);// 如果 data 分配失败，也要释放 table
        return NULL;
    }
    return table;
}; 

static int enlargerSeqTable(SEQTable_t *table){
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
      //先判断pos是否已经超过了容量，再判断enlargerSeqTable返回值是否为非零值，如果是，则扩容失败
    if(table->pos >= table->capacity) {
        if (enlargerSeqTable(table) != 0) {
            printf("Failed to expand the table.\n");
            return -1;
        }
    }
      // 检查pos是否有效
    if(table->pos < 0) {
        printf("Invalid position value.\n");
        return -1;
    }

    table->data[table->pos] = value; //插入元素
    ++table->pos; //指向下一个位置
    return 0; //成功
}

int findSeqTable(const SEQTable_t *table, Element_t value){
    for (int i = 0; i < table->pos; i++) {
        if (table->data[i] == value) {
            return i;
        }
    }
    return -1;
}

void deleteSeqTable(SEQTable_t *table, Element_t value){
    //1.查找value在table中的索引号
    int index = findSeqTable(table, value);
    if(index == -1){
        printf("Element %d not found!\n", value);   
        return -1; //未找到元素
    }
    //2.删除这个元素，把[index+1, pos) 搬移到[index, pos-1)，从后一个往前覆盖
    for(int i = index + 1; i < table->pos; i++){
        table->data[i - 1] = table->data[i];

    }
    --table->pos; //指向下一个位置
    return 0; //成功

};
void showSeqTable(const SEQTable_t *table){
    printf("pos/capacity: %d/%d\n", table->pos, table->capacity);
    for(int i = 0; i < table->pos; i++){
        printf("%d ", table->data[i]);
    }
    printf("\n");
};


//main函数测试
int main() {
    SEQTable_t *table = createSeqTable(10);

    for(int i = 0; i < 10; i++){
        pushbackSeqTable(table, i+100);
    }
    showSeqTable(table);
    printf("===========\n");
    pushbackSeqTable(table, 500);
    showSeqTable(table);
    //deleteSeqTable(table, 103);

    showSeqTable(table);
    releaseSeqTable(table);
    return 0;
}