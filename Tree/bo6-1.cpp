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
