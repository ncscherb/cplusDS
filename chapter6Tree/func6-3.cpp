//fun6-3.cpp bo6-2.cpp和func9-1.cpp调用
//构造空二叉树
void InitBiTree(BiTree &T){
    T=NULL;
}

//销毁二叉树
void DestroyBiTree(BiTree &T){
    if(T){
        if(T->lchild)
            DestroyBiTree(T->lchild);
        if(T->rchild)
            DestroyBiTree(T->rchild);
        free(T); //释放根节点
        T=NULL;
    }
}

//先序递归遍历T
void PreOrderTraverse(BiTree T,void(*Visit)(TElemType)){
    if(T){
        Visit(T->data);
        PreOrderTraverse(T->lchild,Visit);
        PreOrderTraverse(T->rchild,Visit);
    }
}
//中序递归遍历T
void PreOrderTraverse(BiTree T,void(*Visit)(TElemType)){
    if(T){
        PreOrderTraverse(T->lchild,Visit);
        Visit(T->data);
        PreOrderTraverse(T->rchild,Visit);
    }
}
