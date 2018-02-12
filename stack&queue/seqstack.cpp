// 顺序栈（存储结构由seqstack.h定义）的基本操作（9个）bo3-1.cpp
#include "seqstack.h"
//构造一个空栈
void InitStack(SeqStack &s){
    s.base=(ElemType*)malloc(STACK_INIT_SIZE* sizeof(ElemType));
    if(!s.base)
        exit(OVERFLOW); //存储分配失败
    s.top=s.base;
    s.stacksize=STACK_INIT_SIZE;
}

//销毁栈s，s不再存在
void DestoryStack(SeqStack &s){
    free(s.base);
    s.base=NULL;
    s.top=NULL;
    s.stacksize=0;
}

//把S置为空栈
void ClearStack(SeqStack &s){
    s.top=s.base;
}

Status StackEmpty(SeqStack s){
    if(s.base==s.top)
        return TRUE;
    else
        return FALSE;
}

int StackLength(SeqStack s){
    return s.top-s.base;
}

void Push(SeqStack &s, ElemType e){
    if((s.top-s.base)>=s.stacksize){
        s.base=(ElemType*)realloc(s.base,(s.stacksize+STACK_INCREMENT)* sizeof(ElemType));
        if(!s.base){
            exit(OVERFLOW);
        }
        s.stacksize=s.stacksize+STACK_INCREMENT;
        s.top=s.base+s.stacksize;
    }

    *s.top++=e; //注意逻辑，当s中有元素时，top指向的是下一个元素将要插入的位置
}

Status GetTop(SeqStack s,ElemType &e){
    if(s.top>s.base){
        e = *(s.top-1);
        return OK;
    }else{
        return ERROR;
    }
}


Status Pop(SeqStack &s,ElemType &e){
    if(s.top>s.base){
        e=*(--s.top);
        return OK;
    }else
        return ERROR;
}

//从栈底到栈顶依次对栈中每个元素调用函数visit()
void StackTraverse(SeqStack s,void(*visit)(ElemType)){
    while(s.top>s.base){
        visit(*s.base++);
    }
    printf("\n");
}