//算法3.1
typedef int SElemType;
#include "../c1.h"
#include "c3-1.h"
#include "bo3-1.cpp"
//------------algo3-1-------------
//对于输入的任意一个非负十进制整数，打印输出与其值相等的N位二进制数
//value为非负整数
void Conversion(unsigned value, int n){
    SeqStack s;
    InitStack(s); //初始化栈
    SElemType e;

    while(value!=0){  //当n不等于0
        Push(s,value%n); //入栈value除以n的余数（n进制的低位）
        value=value/n;  //得到商
    }

    while (!StackEmpty(s)){ //当栈不为空时
        Pop(s,e);   //弹出栈顶元素且赋值给e
        printf("%d",e); //输出e
    }

    printf("\n");
}

int main(){
    Conversion(10,2);
}

