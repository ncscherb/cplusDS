// c6-1.h 二叉树的顺序存储表示
#define MAX_TREE_SIZE 100 //二叉树的最大节点数
typedef ElemType SqBiTree[MAX_TREE_SIZE]; //0号单元存储根节点

struct position{
    int level,order; //节点的层，本层序号(按满二叉树计算)
};