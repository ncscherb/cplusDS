//线性表的单链表存储结构--头文件 bo2-2.cpp

struct LNode{
    ElemType data; //用于存储数据
    LNode *next;  //用于指向下一个节点
};

typedef LNode *LinkList; //另一种定义LinkList的方法,LinkList表示使用指正定义

class ListSingle {
public:
    //基本方法
    void InitList(LinkList &L);
    void DestoryList(LinkList &L);
    void ClearList(LinkList &L);
    Status ListEmpty(LinkList L);
    int ListLength(LinkList L);
    Status GetElem(LinkList L, int i, ElemType &e);
    int LocateElem(LinkList L,ElemType e,Status(*compare)(ElemType,ElemType));
    Status PriorElem(LinkList L,ElemType cur_e,ElemType &pre_e);
    Status NextElem(LinkList L,ElemType cur_e,ElemType &next_e);
    Status ListInsert(LinkList L,int i,ElemType e);
    Status ListDelete(LinkList L,int i,ElemType &e);
    void ListTraverse(LinkList L,void(*vi)(ElemType));

};


