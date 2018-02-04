#include <iostream>

typedef int ElemType;
#include "c1.h"
#include "linear/c2-1.h"
#include "linear/listSingle.cpp"
#include "linear/func2-3.cpp"
using namespace std;

int main(){

    ListSingle ls = ListSingle();

    LinkList l1,l2,l3;
    ls.CreateList2(l1,5);
    ls.ListTraverse(l1,printd);
    ls.CreateList2(l2,8);
    ls.ListTraverse(l2,printd);
    ls.InitList(l3);
    ls.MergeList(l1,l2,l3);
    ls.ListTraverse(l3,printd);

    ls.ListTraverse(l1,printd);
    int e;
    Status status=ls.GetElem(l1,90,e);
    cout<<e<<status<<endl;

    cout<<ls.ListLength(l1)<<endl;

}
