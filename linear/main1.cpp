#include <iostream>

typedef int ElemType;
#include "../c1.h"
#include "c2-1.h"
#include "func2-3.cpp"
#include "bo2-1.cpp"

int main1(){
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
}
