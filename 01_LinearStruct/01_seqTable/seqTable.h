#pragma once//防止头文件重复包含

//结构声明
typedef int Element_t;

//定义顺序表的表头结构
typedef struct 
{
    Element_t *data; //数据区
    int pos;      //当前长度
    int capacity;    //最大容量
} SEQTable_t;

SEQTable_t *createSeqTable(int n); //创建顺序表
void deleteSeqTable(SEQTable_t *pSeqTable); //删除顺序表
int insertSeqTable(SEQTable_t *pSeqTable, int pos, Element_t data); //插入元素