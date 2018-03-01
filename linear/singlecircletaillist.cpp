//--------------bo2-4.cpp(85ppt)-------
//设立尾指针（L指向尾节点）的单循环链表（存储结构由singlelist.h定义）的12基本操作
#include "c2-2.h"

//构造一个空的线性表L
void InitList(LinkList &L){
    //产生头节点，并使L指向此头节点
    L=(LinkList)malloc(sizeof(LNode));
    if(!L) //存储分配失败
        exit(ERROR);
    L->next=L; //指针域指向头结点
}

//销毁线性表L
void DestoryList(LinkList &L){
    LinkList q,p=L->next; //p指向头节点(L指向的是头结点)

    while (p!=L){ //没到表尾
        q=p;
        p=p->next;
        free(q);
    }

    free(L);
    L=NULL;
}

//将表置为空表
void ClearList(LinkList &L){ //改变L用&
    LinkList p,q;
    p=L->next;//p指向第一个节点
    L=L->next;//L指向头结点

    while(p!=L){ //没到尾表时
        q=p->next;
        free(p);
        p=q;
    }

    L->next=L; //头结点指正指向自身
}

//判断链表L是否为空
Status ListEmpty(LinkList L){
    if(L->next==L)
        return TRUE;
    else
        return FALSE;
}

//返回列表的长度
int ListLength(LinkList L){
    LinkList p=L->next;//p指向头节点
    int i=0;

    while(p!=L){ //没到尾表
        p=p->next;
        i++;
    }

    return i;
}


//当第i个元素存在时，将第i个元素的值赋值给e，并返回OK
Status GetElem(LinkList L, int i,ElemType &e){
    int k=0;
    LinkList p=L->next,q;

    if(i<0||i>ListLength(L)){
        return ERROR;
    }

    while(k<i){
        k++;
        p=p->next;
    }

    e=p->data;
    return OK;
}

//返回L中第一个与e满足关系compare()数据元素的位序
//若这样的数据元素不存在，则返回值为0
int LocateElem(LinkList L, ElemType e, Status(*compare)(ElemType,ElemType)){
    LinkList p=L->next,q=p->next;
    int i=0;

    while (q!=p){
        i++;
        if(compare(e,q->data))
            return i;
        q=q->next;
    }

    return 0;
}

//若cur_e是L的数据元素，且不是第一个，用pre_e返回它的前驱，
//否则操作失败，pre_e无定义
Status PriorElem(LinkList L,ElemType cur_e,ElemType &pre_e){
    LinkList p=L->next->next,q; //p指向第一个节点
    q=p->next;//指向下一个节点

    //p保留前一个节点，q是当前节点
    while (q!=L->next){
        if(q->data==cur_e){
            pre_e = p->data;
            return TRUE;
        }
        p=q;
        q=q->next;
    }

    return FALSE;
}

//若cur_e是L的数据元素，且不是最后一个，则用next_e返回它的后继
Status NextElem(LinkList L,ElemType cur_e,ElemType &next_e){
    LinkList p=L->next->next;
    while (p!=L){
        if(cur_e==p->data){
            next_e=p->next->data;
            return TRUE;
        }
        p=p->next;
    }
    return FALSE;

}

//在L的第i个位置插入元素e
Status ListInsert(LinkList &L, int i, ElemType e){
    LinkList p=L->next,q; //p指向头结点--因此L始终指向的尾节点
    int k=1;

    if(i<0 || i>ListLength(L)+1){ //可以在最后一位插入
        return ERROR;
    }

    //首先找到i的前一个位置,并且i要小于循环列表的长度
    while (k<i){
        p=p->next;
        k++;
    }
    //插入元素
    q=(LinkList)malloc(sizeof(LNode));
    q->data=e;
    q->next=p->next;
    p->next=q;
    //如果是在最后一个插入的q，则改变位置针的位置，使其指向q
    if(p==L){
        L=q;
    }
    return OK;
}

//删除L的第i个元素，并由e返回其值
//方法：找到其上一个元素，改变其指针的指向
Status ListDelete(LinkList &L, int i, ElemType &e){//改变列表的值，用&
    LinkList p=L->next,q;
    int k=1;

    if(i<0 || i>ListLength(L))
        return ERROR;

    while (k<i){
        p=p->next;
        k++;
    }

    q=p->next;
    e=q->data;
    p->next=p->next->next;

    if(q==L){ //如果删除的是表尾元素
        L=p;
    }

    return OK;
}

//依次对L的每个元素调用vi()函数
void ListTraverse(LinkList L,void(*vi)(ElemType)){
    LinkList p=L->next->next;

    while (p!=L->next){
        vi(p->data);
        p=p->next;
    }
    printf("\n");
}