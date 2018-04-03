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

//由文件创建二叉树
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

//二叉树T存在
TElemType Root(BiTree T){
    if(BiTreeEmpty(T))
        return Nil;
    else
        return T->data;
}

//二叉树T存在，p指向T中某个结点,返回该节点的值
TElemType Value(BiTree p){
    return p->data;
}

//给p所指节点赋值value
void Assign(BiTree p,TElemType value){
    p->data=value; //为单个字符
}

typedef BiTree QElemType;//设队列元素为二叉树的指针类型
#include "../chapter3stack&queue/c3-2.h"
#include "../chapter3stack&queue/bo3-2.cpp"
//e是二叉树中某个结点，若e是非根节点，则返回它的双亲，否则返回“空”
TElemType Parent(BiTree T,TElemType e){
    BiTree p;
    LinkQueue q;

    if(T->data==e)
        return Nil;

    InitQueue(q);
    EnQueue(q,T);

    while (!QueueEmpty(q)){
        DeQueue(q,p);
        if(p->lchild&&p->lchild->data==e || p->rchild&&p->rchild->data==e)
            return p->data;
        else{
            if(p->lchild)
                EnQueue(q,p->lchild);
            if(p->rchild)
                EnQueue(q,p->rchild);
        }
    }

    return Nil; //没有找到e
}

//返回二叉树T中指向元素值为s的节点的指针
BiTree Point(BiTree T,TElemType s){
    LinkQueue q;
    QElemType p;

    if(T){
        InitQueue(q);
        EnQueue(q,T);

        while (!QueueEmpty(q)){
           DeQueue(q,p);
            if(p->data==s)
                return p;
            if(p->lchild)
                EnQueue(q,p->lchild);
            if(p->rchild)
                EnQueue(q,p->rchild);
        }
    }
    return NULL;
}



