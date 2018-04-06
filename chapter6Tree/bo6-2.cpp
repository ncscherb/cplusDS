//bo62.cpp 二叉树的二叉链表存储（存储结构由c6-2.h定义）的基本操作22个

#define ClearBiTree DestoryBiTree
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

//返回e的左孩子，若e无左孩子，则返回空值
TElemType LeftChild(BiTree T,TElemType e){
    BiTree p;

    if(!T)
        return Nil;

    p=Point(T,e);
    if(p&&p->lchild){
        return p->lchild->data;
    }

    return Nil;
}
//返回e的右孩子，若e无右孩子，则返回空值
TElemType RightChild(BiTree T,TElemType e){
    BiTree p;

    if(!T)
        return Nil;

    p=Point(T,e);
    if(p&&p->rchild){
        return p->rchild->data;
    }

    return Nil;
}

//返回e的左邻居，若e无左邻居，则返回空值
TElemType LeftSibling(BiTree T,TElemType e){
    TElemType a;
    BiTree p;
    if(T){
        a = Parent(T,e);
        if(a!=Nil){
            if(p&&p->lchild&&p->rchild&&p->rchild->data==e)
                return p->lchild->data;
        }
    }
    return Nil;
}

//返回e的右邻居，若e无右邻居，则返回空值
TElemType RightSibling(BiTree T,TElemType e){
    TElemType a;
    BiTree p;
    if(T){
        a = Parent(T,e);
        if(a!=Nil){
            p=Point(T,a);
            if(p&&p->rchild&&p->lchild&&p->lchild->data==e)
                return p->lchild->data;
        }
    }
    return Nil;
}

//根据LR为0或1，插入c为T中p所指节点的左或右子树
//p所指节点的原有左或右子树则成为c的右子树
Status InsertChild(BiTree p,int LR,BiTree c){
    if(p){
        if(LR){
            c->rchild=p->rchild;
            p->rchild=c;
        }else{
            c->rchild=p->lchild;
            p->lchild=c;
        }
        return OK;
    }
    return ERROR;
}

//根据LR为0或1，删除T中p所指节点的左或右子树
Status DeleteChild(BiTree p,int LR){
    if(p){
        if(LR==0)
            ClearBiTree(p->lchild);
        else
            ClearBiTree(p->rchild);
        return OK;
    }
    return ERROR;
}

typedef BiTree SElemType; //设栈元素为二叉树的指针类型
#include "../chapter3stack&queue/c3-1.h"
#include "../chapter3stack&queue/bo3-1.cpp"
//中序遍历二叉树T的非递归算法（利用栈），对每个数据元素调用函数Visit
void InOrderTraverse1(BiTree T,void(*Visit)(TElemType)){
    SeqStack s;
    BiTree p;

    InitStack(s);

    while (T||!StackEmpty(s)){
        if(T){
           Push(s,T);
            T=T->lchild;
        }else{
            Pop(s,p);
            Visit(p->data);
            T=p->rchild;
        }
    }
    printf("\n");
}

//中序遍历二叉树T的非递归算法（利用栈），对每个数据元素调用visit
void InOrderTraverse2(BiTree T,void(*Visit)(TElemType)) {
    SeqStack s;
    BiTree p;

    InitStack(s);
    if(T){
        Push(s,T);
        while (!StackEmpty(s)){
            while(GetTop(s,p)&&p)
                Push(s,p->lchild);

            Pop(s,p); //弹出空指针

            if(!StackEmpty(s)){
               Pop(s,p);
               Visit(p->data);
               Push(s,p->rchild); //通过右子节点是否为空来判断该节点是否遍历已经完成
            }
        }
    }
}

//后序递归遍历T
void PostOrderTraverse(BiTree T,void(*Visit)(TElemType)){
    if(T){
        PostOrderTraverse(T->lchild,Visit);
        PostOrderTraverse(T->lchild,Visit);
        Visit(T->data); //最后访问根节点
    }
}

//非递归--后序遍历
void PostOrderTraverse1(BiTree T,void(*Visit)(TElemType)){
    SeqStack s;
    SeqStack s1;//辅助栈，用来存储根节点
    BiTree p;
    BiTree p1;

    InitStack(s);
    InitStack(s1);
    while (T||!StackEmpty(s)){
        if(T){
            Push(s,T);
            T=T->lchild;
        }else{
            Pop(s,p);
            GetTop(s1,p1);
            if(p->rchild&&p1!=p){ //右子树不为空并且该节点未被访问过则入栈
                T=p->rchild;
                Push(s,p);
                Push(s1,p);
            }else{
               Visit(p->data);
                if(p1==p) //子树出栈条件
                    Pop(s1,p1);
            }
        }
    }
    printf("\n");
}

//层序递归遍历T(利用队列)
void LevelOrderTraverse(BiTree T,void(*Visit)(TElemType)){
    LinkQueue q;
    QElemType e;

    InitQueue(q);
    if(T){
        EnQueue(q,T);
        while (!QueueEmpty(q)){
            DeQueue(q,e);
            Visit(e->data);
            if(e->lchild)
                EnQueue(q,e->lchild);
            if(e->rchild)
                EnQueue(q,e->rchild);
        }
    }
}
