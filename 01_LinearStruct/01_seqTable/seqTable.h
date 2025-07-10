//防止头文件重复包含
#pragma once

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
SEQTable_t *createSeqTable(int n); //创建顺序表
void releaseSeqTable(SEQTable_t *table); //释放顺序表
int pushbackSeqTable(SEQTable_t *table, Element_t value); //在表尾插入元素
int insertSeqTable(SEQTable_t *table, int index, Element_t value); //在指定位置插入元素
int findSeqTable(const SEQTable_t *table, Element_t value); //查找元素是否存在
int deleteSeqTable(SEQTable_t *table, Element_t value); //删除指定元素
void showSeqTable(const SEQTable_t *table); //显示顺序表内容
