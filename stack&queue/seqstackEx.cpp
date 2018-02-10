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

//------------algo3-3-------------
//括号()、[]和{}匹配的检验
//对于输入的任意一个字符串，检验括号是否配对
void check(){
    SeqStack s;
    char ch[80],*p,e; //用来存储字符串
    InitStack(s);
    printf("请输入括号（()、[]和{}）的表达式:");
    gets(ch);  //获取用户从界面输入的值
    p=ch;  //p指向字符串的首字符

    while(*p){  //没到尾串
        switch (*p){
            case '(':
            case '[':
            case '{':
                Push(s,*p++); //左括号入栈,且p++
                break;
            case ')':
            case ']':
            case '}':
                if(!StackEmpty(s)){
                    Pop(s,e);  //弹出栈顶元素
                    //出现三种匹配情况之外的其他情况
                    if(!((e=='{' && *p++=='}') || (e=='(' && *p++==')') || (e=='[' && *p++==']'))){
                        printf("左右括号不匹配\n");
                        exit(ERROR);
                    }
                }else{
                    printf("缺乏左括号");
                    exit(ERROR);
                }
                break;
            default:p++; //其他情况不处理，指针向后移
        }
    }

    if(StackEmpty(s))
        printf("左右括号匹配");
    else
        printf("缺乏右括号");
}
