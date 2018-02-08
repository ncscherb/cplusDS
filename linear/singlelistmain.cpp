#include <iostream>

typedef int ElemType;
#include "../c1.h"
#include "singlelist.cpp"
#include "../func2-3.cpp"
#include "singlelistEx.cpp"
using namespace std;

int main(){
    ElemType e;
    ListSingle ls = ListSingle();

    LinkList l1,l2,l3;
    cout<<"创建带头结点的单链表"<<endl;
    CreateList2(l1,5);
    ls.ListInsert(l1,6,10);
    ls.ListTraverse(l1,printd);
    CreateList2(l2,8);
    ls.ListTraverse(l2,printd);
    cout<<"---删除元素---"<<endl;
    ls.ListDelete(l1,3,e);
    ls.ListTraverse(l1,printd);
    ls.InitList(l3);
    cout<<"合并两个链表"<<endl;
    //MergeList(l1,l2,l3);
    ls.ListTraverse(l3,printd);

    Status status=ls.GetElem(l1,90,e);
    cout<<e<<status<<endl;

    cout<<ls.ListLength(l1)<<endl;
    cout<<ls.LocateElem(l2,15,equal)<<endl;
    cout<<"prior:"<<ls.PriorElem(l1,4,e);
    cout<<" e:"<<e<<endl;

    cout<<"---返回后继---"<<endl;
    ls.NextElem(l2,4,e);
    cout<<"e:"<<e;


}
