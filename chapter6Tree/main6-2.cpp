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
    LevelOrderTraverse(T,visitT);
}
