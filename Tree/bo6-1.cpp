#include "c6-1.h"

//构造空二叉树T,因为T是数组名，故不需要&
void InitBiTree(SqBiTree T){
    int i;
    for(i=0;i<MAX_TREE_SIZE;i++){
        T[i]=Nil; //初始值为空（Nil在主程序中定义)
    }

}

//按层序次输入二叉树中节点的值（字符型或整型），构造顺序存储二叉树
void CreateBiTree(SqBiTree T){
    int i=0;
    InitBiTree(T); //构造空二叉树
    int l;
    char s[MAX_TREE_SIZE];

}
