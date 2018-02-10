//算法3.1
//------------algo3-1-------------
//对于输入的任意一个非负十进制整数，打印输出与其值相等的N位二进制数
//value为非负整数
void Conversion2(unsigned value, int n){
    SeqStack s;
    InitStack(s); //初始化栈
    ElemType e;

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


//------------algo3-2-------------
//对于输入的任意一个非负十进制整数，打印输出与其值相等的16进制数
void Conversion16(){
    SeqStack s;
    unsigned n;
    ElemType e;
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
