//------------algo3-2-------------
typedef int SElemType;
#include "../c1.h"
#include "c3-1.h"
#include "bo3-1.cpp"
//对于输入的任意一个非负十进制整数，打印输出与其值相等的16进制数
void Conversion16(){
    SeqStack s;
    unsigned n;
    SElemType e;
    InitStack(s);
    printf("将10进制整数n转换为16进制数，请输入：n(n>=0）=");
    scanf("%u",&n);

    while (n){
        Push(s,n%16);
        n=n/16;
    }

    while(!StackEmpty(s)){
        Pop(s,e);
        if(e>9){
            printf("%c",e+55);
        }else
            printf("%d",e);
    }
    printf("\n");
}

int main(){
    Conversion16();
}

