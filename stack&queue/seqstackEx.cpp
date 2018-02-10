//算法3.1
//------------algo3-1-------------
//对于输入的任意一个非负十进制整数，打印输出与其值相等的N位二进制数
SeqStack Conversion(unsigned value, int n){
    SeqStack s;
    InitStack(s);


    while(value!=0){
        Push(s,value%n);
        value=value/n;
    }

    return s;
}
