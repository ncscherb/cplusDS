//c2-2.h 线性表的单链表存储结构

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

    //扩展方法
    void CreateList2(LinkList &L,int n);
    void MergeList(LinkList La, LinkList Lb, LinkList &Lc);

    void ListTraverse(LinkList L,void(*vi)(ElemType));
};


