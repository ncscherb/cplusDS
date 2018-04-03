//线性表的单链表存储结构--头文件 bo2-2.cpp

struct LNode1{
    ElemType data; //用于存储数据
    LNode *next;  //用于指向下一个节点
};

typedef LNode *LinkList; //另一种定义LinkList的方法,LinkList表示使用指正定义

