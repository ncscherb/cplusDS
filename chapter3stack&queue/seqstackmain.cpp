typedef int ElemType ;
#include "../c1.h"
#include "bo3-1.cpp"
#include "../linear/func2-3.cpp"
#include "algo3-1.cpp"
using namespace std;

int main(){
    SeqStack s;
    ElemType e;

    InitStack(s);
    Push(s,5);
    Push(s,3);
    Push(s,9);

    Pop(s,e);
    cout<<e<<endl;
    GetTop(s,e);
    cout<<e<<endl;
    StackTraverse(s,printd);

    cout<<"二进制转换:";
    Conversion2(10,2);
    //StackTraverse(s1,printd);
    //Conversion16();


}