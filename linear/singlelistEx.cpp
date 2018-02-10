//-------------------------单链表扩展方法-----------------------
//-------------------------algo2-5.cpp------------------------
//正位序（插在表尾），输入n个元素的值，建立带表头结构的单链线性表L
//注：指针调用类或结构体中的值用->，类型变量调用用.

//逆位序（插在表头），输入n个元素的值，建立带表头结构的单链线性表L
void CreateList(LinkList &L, int n){
    LinkList p,q;

    L = (LinkList)malloc(sizeof(LNode)); //创建头结点
    L->next=NULL; //先建立一个带头结点的单链表
    p=L;

    for(int i=1;i<=n;i++){
       q=(LinkList)malloc(sizeof(LNode)); //生成新节点
        q->data=i;  //输入数据元素的值
        q->next=p->next; //插入到表头
        p->next=q;
    }

}

void CreateList2(LinkList &L, int n) {
    LinkList p,q;
    L=(LinkList)malloc(sizeof(LNode));
    L->next=NULL;
    p=L;

    for(int i=1;i<=n;i++){
        q=(LinkList)malloc(sizeof(LNode));
        q->data=i;
        q->next=NULL;

        p->next=q;
        p=q;
    }
}

//已知单链线性表La和Lb的元素值按非递减排列
//归并La和Lb得到新的单链线性表Lc，Lc的元素也按值非递减排列
//这种方式合并有问题
void MergeList(LinkList La, LinkList Lb, LinkList &Lc) {
    LinkList p,q,k;
    p=La->next;
    q=Lb->next;
    k=Lc;

    while (p && q){
        if(p->data>=q->data){
            k->next=q;
            q=q->next;
            k=k->next;
        } else{
            k->next=p;
            p=p->next;
            k=k->next;
        }
    }

    k->next=p?p:q;
}

