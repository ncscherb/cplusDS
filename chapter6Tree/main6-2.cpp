//mian6-2.cpp 检验bo-2.cpp的主程序，利用条件编译选择数据类型（另一种方法）
#define CHAR //字符类型

#include "../c1.h"
#ifdef CHAR
    typedef char TElemType;
    TElemType Nil='#'; //字符型一空格符为空
    #define form "%c"//输入输出的格式为%c
#endif
#ifdef INI
    typedef int TElemType;
    TElemType Nil=0; //字符型一空格符为空
    #define form "%d" //输入输出的格式为%c
#endif

#include <fstream>
using namespace std;
#include "c6-2.h"
#include "bo6-2.cpp"

void visitT(TElemType e){
    printf(form" ", e);
}

int main(){
    int i;
    BiTree T,p,c;
    TElemType e1,e2;
    InitBiTree(T);
    printf("构造空二叉树，数空否？%d(1:是 0：否)，树的深度=%d\n",BiTreeEmpty(T),BiTreeDepth(T));
    e1=Root(T);
    if(e1!=Nil)
        printf("二叉树的根为：" form "\n",e1);
    else
        printf("树空，无根\n");
#ifdef CHAR
    printf("请先序输入二叉树（如：ab三个空格表示a为根节点，b为左子二叉树）");
#endif
#ifdef INT
    printf("请先序输入输入二叉树（如：1 2 0 0 0表示1为根节点，2为左子树的二叉树)");
#endif
    ifstream inFile("E:\\Users\\cplusDS\\chapter6Tree\\main6-2");
    CreateBiTreeF(T, inFile);
    inFile.close();
    printf("构造空二叉树，数空否？%d(1:是 0：否)，树的深度=%d\n",BiTreeEmpty(T),BiTreeDepth(T));
    e1=Root(T);
    if(e1!=Nil)
        printf("二叉树的根为：" form "\n",e1);
    else
        printf("树空，无根\n");
    printf("中序递归遍历二叉树：\n");
    InOrderTraverse2(T,visitT);
    printf("后序递归遍历二叉树：\n");
    PostOrderTraverse1(T,visitT);
    printf("\n请输入一个已存在节点的值:");
    scanf( form,&e1);
    p=Point(T,e1);//p为e1的指针
    printf("节点的值为" form "\n",Value(p));
    printf("欲改变此节点的值，请输入新值:");
    scanf("%*c" form "%*c",&e2); //有一个%*c吃掉回车符，为调用CreateBiTree做准备
    Assign(p,e2);
    printf("层序递归遍历二叉树：\n");
    LevelOrderTraverse(T,visitT);
    e1=Parent(T,e2);
    if(e1!=Nil)
        printf("%c的双亲是"form"\n",e2,e1);
    else
        printf(form"没有双亲\n",e2);
    e1=LeftChild(T,e2);
    if(e1!=Nil)
        printf(form"的左孩子是"form"\n",e2,e1);
    else
        printf(form"没有左孩子\n",e2);
    e1=RightChild(T,e2);
    if(e1!=Nil)
        printf(form"的右孩子是"form"\n",e2,e1);
    else
        printf(form"没有右孩子\n",e2);
    e1=LeftSibling(T,e2);
    if(e1!=Nil)
        printf(form"的左兄弟是"form"\n",e2,e1);
    else
        printf(form"没有左兄弟\n",e2);
    e1=RightSibling(T,e2);
    if(e1!=Nil)
        printf(form"的右兄弟是"form"\n",e2,e1);
    else
        printf(form"没有右兄弟\n",e2);



}
