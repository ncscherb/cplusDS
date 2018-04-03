typedef char SElemType;
#include "../c1.h"
#include "c3-1.h"
#include "bo3-1.cpp"
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

int main(){
    check();
}

