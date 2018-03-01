#include <iostream>

typedef int ElemType;
#include "../c1.h"
#include "seqlist.h"
#include "func2-3.cpp"
#include "seqlist.cpp"
#include "seqlistEx.cpp"
using namespace std;

int main(){
    SqList La,Lb;
    int j;

    InitList(La); //创建空表La,如果不成功，则会退出程序的运行
    for(int i=1;i<5;i++)
        ListInsert(La,i,i);

    ListInsert(La,3,1);
    PrintList(La);

    ElemType r;
    PriorElem(La, 3,r);
    std::cout<<"prior"<<r<<std::endl;
    NextElem(La, 3,r);
    std::cout<<"next"<<r<<std::endl;
    ListDelete(La, 3,r);
    std::cout<<"delete"<<r<<std::endl;
    PrintList(La);


    InitList(Lb); //创建空表La,如果不成功，则会退出程序的运行
    for(int i=3;i<=6;i++)
        ListInsert(Lb,i-2,i);

    printf("\n");
    Union(La,Lb);
    PrintList(La);

    cout<<"---测试归并---"<<endl;
    cout<<"La:";
    PrintList(La);
    cout<<"Lb:";
    ListInsert(Lb,5,7);
    ListInsert(Lb,6,9);
    PrintList(Lb);

    SqList Lc;
    MergeList(La,Lb,Lc);
    cout<<"Lc:";
    PrintList(Lc);

    cout<<"---测试归并2---"<<endl;
    SqList Ld;
    MergeList2(La,Lb,Ld);
    cout<<"Ld:";
    PrintList(Ld);

    cout<<"---测试归并3---"<<endl;
    SqList Le;
    MergeList3(La,Lb,Le);
    cout<<"Ld:";
    PrintList(Ld);
}
