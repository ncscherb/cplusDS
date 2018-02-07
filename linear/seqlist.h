//c2-1.h线性表的动态分配顺序存储结构
#define LIST_INI_INIT_SIZE 10 //线性表存储空间的初始分配量
#define LIST_INCREMENT 2 //线性表存储空间的分配增量

struct SqList{
    ElemType *elem; //存储空间基址--未定义可以声明吗？
    int length;  //当前线性表的长度
    int listsize; //当前分配的存储空间容量(以sizeof(ElemType)为单位)
};