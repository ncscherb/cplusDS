//#include "c6-1.h"

//构造空二叉树T,因为T是数组名，故不需要&
void InitBiTree(SqBiTree T){
    int i;
    for(i=0;i<MAX_TREE_SIZE;i++){
        T[i]=Nil; //初始值为空（Nil在主程序中定义)
    }

}

//按层序次输入二叉树中节点的值（字符型或整型），构造顺序存储二叉树
//数据的输入形式为：6 4 8 0 5 7 0 999 在这里，第一个0便是左子树为空
void CreateBiTree(SqBiTree T){
    int i=0;
    InitBiTree(T); //构造空二叉树
#if CHAR //如果变量名的值为真，则执行这后面的语句（节点类型为字符型）
    int l;
    char s[MAX_TREE_SIZE];
    cout<<"请按层序输入结点的值（字符），空格表示空节点，节点数<="<<MAX_TREE_SIZE<<":"<<endl;
    gets(s); //获取用户输入的字符串
    l=strlen(s); //求字符串长度
    for(;i<l;i++){
        T[i]=s[i];
    }
#else //节点类型为整型
    cout<<"请按层序输入结点的值（整型），0表示空节点,输入999结束，节点数<="<<MAX_TREE_SIZE<<":"<<endl;
    while (1){
        cin>>T[i];
        if(T[i]==999){
            T[i]=Nil; //设置值为初始值
            break;
        }
        i++;
    }

#endif
    for(i=1;i<MAX_TREE_SIZE;i++){
        //printf("%d,%d\n",i,(i+1)/2-1);
        //如果一个节点不是根节点，判断它是否有双亲（根据满二叉树原理）
        if(i!=0&&T[(i+1)/2-1]==Nil&&T[i]!=Nil){
            cout<<"出现无双亲的非根节点"<<T[i]<<endl;
            exit(ERROR);
        }
    }
}

//初始条件：二叉树T存在。
//操作结果：若T为空二叉树，则返回T
Status BiTreeEmpty(SqBiTree T){
    if(T[0]==Nil) //根节点为空，则树空
        return TRUE;
    else
        return FALSE;
}

//二叉树T存在，返回二叉树的深度
int BiTreeDepth(SqBiTree T){
    int i,j=-1;
    for(i=MAX_TREE_SIZE-1;i>=0;i--){
        if(T[i]!=Nil)
            break;
    }

    i++; //因为树是从0开始滴

    //满二叉树深度为i时共有节点数为 2^i-1
    do{
        j++;
    }while (i>=pow(2,j));//是否要减1->不能减1，如果减一，此时j还会加1

    return j;
}

//当T不空，用e返回T的根，并返回OK
Status Root(SqBiTree T, ElemType &e){
    if(BiTreeDepth(T))
        return ERROR;
    else{
        e=T[0];
        return OK;
    }
}


//e是T中某个结点(的位置)
//返回处于位置e(层，本层序号)的节点的值
//position中level表示节点所在的层，e表示节点在本层的序号(按满二叉树算)
ElemType Value(SqBiTree T, position e){
    //思路：首先找到本层的上一层最后一个节点的序号(2^level-1)-1，并且数组是从0开始的，故order减2
    return T[int(pow(2,e.level-1)+e.order-2)];
}

//e是二叉树T中某个结点（的位置）
//给处于位置e（层，本层序号）的结点赋新值value
Status Assign(SqBiTree T,position e,ElemType value){
    int i=int(pow(2,e.level-1)+e.order-2);
    //给叶节点赋非空值但双亲为非空(赋值的结点作为叶节点)
    if(value !=Nil && T[(i+1)/2-1]==Nil)
        return ERROR;
    // 赋值的结点作为父结点时，若有非空子节点，该节点的值不能为空
    else if(value==Nil&&(T[2*i+1]!=Nil || T[2*i+2]!=Nil))
        return ERROR;
    T[i]=value;

    return OK;
}

//e是T中某个结点
//若e是T的非根节点，则返回它的双亲，否则返回“空”
ElemType Parent(SqBiTree T,ElemType e){
    int i;

    if(T[0]==Nil)
        return Nil;

    for(i=1;i<MAX_TREE_SIZE;i++){
        if(e==T[i]){
            return T[int((i+1)/2-1)];
        }
    }

    return Nil;
}

//e是T中某个结点，返回e的左孩子，若e无左孩子，返回空
ElemType LeftChild(SqBiTree T,ElemType e){
    int i;
    if(T[0]==Nil){ //空树
        return Nil;
    }

    for(i=0;i<MAX_TREE_SIZE;i++){
        if(e==T[i])
            return T[2*i+1];
    }

    return Nil;
}

//e是T中某个结点，返回e的右孩子，若e无右孩子，返回空
ElemType RightChild(SqBiTree T,ElemType e){
    int i;
    if(T[0]==Nil){ //空树
        return Nil;
    }

    for(i=0;i<MAX_TREE_SIZE;i++){
        if(e==T[i])
            return T[2*i+2];
    }

    return Nil;
}

//e是T中某个结点
//返回e的左兄弟，若e是T的左孩子或无左兄弟，则返回"空"
ElemType LeftSibling(SqBiTree T,ElemType e){
    int i;
    if(T[0]==Nil)
        return Nil;

    for(i=0;i<MAX_TREE_SIZE;i++){
        if(e==T[i] && i%2==0){
            //找到e且序号为偶数（是右孩子）
            return T[i-1];
        }
    }
    return Nil;
}

//e是T中某个结点
//返回e的右兄弟，若e是T的右孩子或无右兄弟，则返回"空"
ElemType RightSibling(SqBiTree T,ElemType e){
    int i;
    if(T[0]==Nil)
        return Nil;

    for(i=0;i<MAX_TREE_SIZE;i++){
        if(e==T[i] && i%2==1){
            //找到e且序号为奇数（是左孩子）
            return T[i+1];
        }
    }
    return Nil;
}

//把从q的j结点开始的子树移为从T的i结点开始的子树
//InsertChild（）用到->递归移动
void Move(SqBiTree q, int j,SqBiTree T,int i){
    if(q[2*j+1]!=Nil) //q的左子树不为空
        Move(q,(2*j+1),T,2*i+1);//把q的j结点的左子树移为T结点的左子树
    if(q[2*j+2]!=Nil)
        Move(q,(2*j+2),T,2*i+2);
    T[i]=q[j]; //把q的j结点移为T的i结点
    q[j]=Nil; //把q的j结点置空
}

//p是T中某个结点的值，LR为0或1，非空二叉树c与T不相交且右子树为空
//根据LR为0或1,插入c为T中p结点的左或又子树
//p结点原有的左或右子树成为c的右子树
void InsertChild(SqBiTree T, ElemType p, int LR, SqBiTree c){
    int i,j,k=0;
    //找到值为p的结点
    for(i=0;i<MAX_TREE_SIZE;i++){
        if(p==T[i])
            break;
    }

    j=2*i+1+LR; //LR=0插入c为p节点的左子树

    if(T[j]!=Nil){ //如果p原来的左子树不为空（如果要插入到左子树的话）
         //把从T的j节点开始的子树移为从j节点右节点开始的子树(?会不会死循环)
        Move(T,j,T,2*j+2);
    }

    Move(c,k,T,j);
}


