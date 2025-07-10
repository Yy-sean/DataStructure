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
void releaseSeqTable(SEQTable_t *table){
    if(table){
        if(table->data){
            free(table->data); //释放数据区内存
        }
        free(table); //释放表头结构体内存
    }
};
int pushbackSeqTable(SEQTable_t *table, Element_t value){

}
void deleteSeqTable(SEQTable_t *table, Element_t value){

};
void showSeqTable(const SEQTable_t *table){

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

    ShowSeqTable(table);
    return 0;
}