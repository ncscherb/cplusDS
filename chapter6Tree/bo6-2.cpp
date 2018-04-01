//bo62.cpp 二叉树的二叉链表存储（存储结构由c6-2.h定义）的基本操作22个

//#include "c6-2.h"
#include "func6-3.cpp"

//按优先次序输入二叉树中节点的值（可为字符型或整型，在主程序中定义）
//构造二叉链表表示的二叉树T。变量Nil表示空（子）树
void CreateBiTree(BiTree &T){
    TElemType ch;
    scanf(form, &ch);
    if(ch==Nil)
        T=NULL;
    else{
        T=(BiTree)malloc(sizeof(BiTNode)); //生成根节点
        if(!T)
            exit(OVERFLOW);
        T->data=ch;
        CreateBiTree(T->lchild); //构造左子树
        CreateBiTree(T->rchild);
    }
}

void CreateBiTreeF(BiTree &T,ifstream &inFile){
    TElemType ch;
    inFile>>ch;
    if(!inFile)
        return;

    if(ch==Nil)
        T=NULL;
    else{
        T=(BiTree)malloc(sizeof(BiTNode)); //生成根节点
        if(!T)
            exit(OVERFLOW);
        T->data=ch;
        T->rchild=NULL;
        T->lchild=NULL;
        CreateBiTreeF(T->lchild,inFile); //构造左子树
        CreateBiTreeF(T->rchild,inFile);
    }
}

//二叉树是否存在
Status BiTreeEmpty(BiTree T){
    if(T)
        return FALSE ;
    else
        return TRUE;
}

//返回T的深度
int BiTreeDepth(BiTree T){
    int i=0,j=0;

    if(!T)
        return 0;

    i=BiTreeDepth(T->lchild);
    j=BiTreeDepth(T->rchild);

    return i>j?i+1:j+1;
}

TElemType Root(BiTree T){

}

