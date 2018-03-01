//-------------bo2-2.cpp--------
//带有头结点的单链表（存储结构由c2-2.h定义）的12个基本操作

#include <iostream>
#include "c2-2.h"

//---------------------------基本方法----------------------
//构造一二空的线性表L->是否加取决于在函数中使用的是地址还是地址存储的值
void ListSingle::InitList(LinkList &L) {
    L = (LinkList)malloc(sizeof(LNode)); //产生头节点，并使L指向此头节点
    if(!L){                //存储分配失败
        exit(OVERFLOW);
    }

    L->next=NULL; //指针域为空
}

//销毁单链表，头指针也要销毁
void ListSingle::DestoryList(LinkList &L) {
    LinkList q;
    while (L){
        q=L->next;
        free(L);
        L=q;
    }
}

//清空单链表，只保留头指针
void ListSingle::ClearList(LinkList &L) {
    LinkList p,q;
    p=L->next;

    while(p){
        q=p->next;
        free(p);
        p=q;
    }

    L->next=NULL;
}

//判断链表是否为空
Status ListSingle::ListEmpty(LinkList L) {
    if(L->next==NULL)
        return TRUE;
    else
        return FALSE;

}

//返回单链表的长度
int ListSingle::ListLength(LinkList L) {
    int len=0;
    LinkList p;
    p=L->next;

    while(p){
        len++;
        p=p->next;
    }

    return len;
}

//L为带头节点的单链表的头指正。
//当第i个元素存在是，其赋值给e,同时返回OK,否则返回ERROR
Status ListSingle::GetElem(LinkList L, int i, ElemType &e) {
    int j=1; //j为计数器
    LinkList p,q;
    p=L->next; //p指向第一个节点

    while(p&&j<i){ //顺序向后查找，直到p指向第i个元素或p为空
        p=p->next;
        j++;
    }
    if(!p||j>i){
        return ERROR;
    }

    e=p->data;
    return OK;
}

//线性表L已存在，compare()是数据元素判定函数（满足为1，否则为0）
//返回L中第1个与e满关系compare()的数据元素的位序。
//若这样的数据元素不存在，则返回0
int ListSingle::LocateElem(LinkList L, ElemType e, Status (* compare)(ElemType, ElemType)) {
    int i=0;
    LinkList p=L->next;

    while(p){
        ++i;
        if(compare(p->data ,e)){
            return i;
        }
        p=p->next;
    }

    return 0;

}

//若cur_e是L的数据元素，且不是第一个，用pre_e返回它的前驱，并返回OK
Status ListSingle::PriorElem(LinkList L, ElemType cur_e, ElemType &pre_e) {
    LinkList p=L->next,q;
    if(p){
        q=p->next;
        while(q){
            if(q->data==cur_e){
                pre_e=p->data;
                return OK;
            }
            p=q;
            q=q->next;
        }
    }

    return INFEASIBLE;
}

//操作结果：若cur_e是L的数据元素，且不是最后一个，则用next_e返回它的后继，
//并返回OK;否则操作失败，next_e无定义，返回INFEASIBLE
Status ListSingle::NextElem(LinkList L, ElemType cur_e, ElemType &next_e) {
    LinkList p;
    p=L->next;

    while(p){
        if(p->data==cur_e){
           if(p->next!=NULL)
           {
               next_e = p->next->data;
               return OK;
           }
        }else{
            p=p->next;
        }
    }

    return INFEASIBLE;

}

//带头结点的单链线性表L中第i个位置之前插入元素e
Status ListSingle::ListInsert(LinkList L, int i, ElemType e) {
    int j=0;
    LinkList p=L,s;

    while(p&&j<i-1){ //寻找第i-1个节点，即插入节点的前一个节点
        p=p->next;
        j++;
    }

    if(!p||j>i-1){ //i小于1或者大于表长(此时p为空)
        return ERROR;
    }

    s=(LinkList)malloc(sizeof(LNode)); //生成节点
    s->data=e;

    s->next=p->next; //插入L中
    p->next=s;

    return OK;
}

// 在带头结点的单链线性表L中，删除第i个元素，并由e返回其值
Status ListSingle::ListDelete(LinkList L, int i, ElemType &e) {
    LinkList p=L,q;
    int j=1;

    while(p&&j<i){
        p=p->next;
        j++;
    }

    if(!p||j>i){
        return ERROR;
    }

    p->next=p->next->next;
    return OK;
}

//遍历打印线性表
void ListSingle::ListTraverse(LinkList L, void (*vi)(ElemType)) {
    LinkList p=L->next;
    while(p){
        vi(p->data);
        p=p->next;
    }
    printf("\n");
}

