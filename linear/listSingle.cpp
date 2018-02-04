//
// Created by DSL on 2018/2/2.
//

#include <iostream>
#include "listSingle.h"

//构造一二空的线性表L
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

//正位序（插在表尾），输入n个元素的值，建立带表头结构的单链线性表L
//注：指针调用类或结构体中的值用->，类型变量调用用.
void ListSingle::CreateList2(LinkList &L, int n) {
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
void ListSingle::MergeList(LinkList La, LinkList Lb, LinkList &Lc) {
    LinkList p,q,k;
    p=La->next;
    q=Lb->next;
    k=Lc;

    while (p && q){
        if(p->data>q->data){
            k->next=q;
            q=q->next;
            k=k->next;
        } else if(p->data<q->data){
            k->next=p;
            p=p->next;
            k=k->next;
        }else{
            k->next=p;
            p=p->next;
            q=q->next;
            k=k->next;
        }
    }

    k->next=p?p:q;
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
