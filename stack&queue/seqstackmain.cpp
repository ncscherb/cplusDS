typedef int ElemType ;
#include "../c1.h"
#include "seqstack.cpp"
#include "../func2-3.cpp"
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


}