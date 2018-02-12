typedef int ElemType;
#include "../c1.h";
#include "singlecircletaillist.cpp"
#include "../func2-3.cpp"
using namespace std;

int main(){
    LinkList p;
    InitList(p);
    ListInsert(p,1,10);
    ListInsert(p,2,62);
    ListInsert(p,2,1);
    ListInsert(p,4,30);
    int len=ListLength(p);
    cout<<"Length:"<<len<<endl;

    int e;
    GetElem(p,1,e);
    cout<<"GetElem:"<<e<<endl;

    int status=PriorElem(p,10,e);
    cout<<"PriorElem:"<<status<<"--"<<e<<endl;

    status=NextElem(p,10,e);
    cout<<"NextElem:"<<status<<"--"<<e<<endl;

    cout<<"traverse before:";
    ListTraverse(p,printd);
    ListDelete(p,1,e);
    cout<<"traverse after:";
    ListTraverse(p,printd);
}