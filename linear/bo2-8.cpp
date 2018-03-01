//bo2-8.cpp不带头结点的单链表（存储结构由c2-2.h定义）基本操作9个
//L为不带头结点的单链表的头指针
#include "c2-2.h"

//构造一个空的线性表L
void InitList(LinkList &L){
    L=NULL;
}

//将L重置为空表
void ClearList(LinkList &L){
    LinkList p;
    while (L){ //L不为空
        p=L; //p指向首元结点
        L=L->next;
        free(L);
    }
}

//判断线性表是否为空
Status ListEmpty(LinkList L){
    if(L)
        return FALSE;
    else
        return TRUE;
}

//返回线性表元素个数
int ListLength(LinkList L){
   LinkList p;
    p=L;
    int i=0;
    while (p){
        i++;
        p=p->next;
    }

    return i;
}

//L为不带头结点的单链表的头指针,当第i个元素存在时，其值赋给e并返回OK
Status GetElem(LinkList L,int i,ElemType &e){
    int j=1;
    LinkList p=L;

    if(i<1)
        return ERROR;

    while (j<i&&p){
        p=p->next;
        j++;
    }

    //如果存在第i个元素
    if(j==i){
        e=p->data;
        return OK;
    } else
        return ERROR;
}

//返回L中第1个与e满足关系compare()元素的位序。若这样的数据元素不存在，则返回值为0
int LocateElem(LinkList L,ElemType e,Status(*compare)(ElemType,ElemType)){
    
}