//main6-1.cpp 检验bo6-1.cpp的主程序，利用条件编译选择数据类型为char或int
// #define CHAR 1 //字符型
#define CHAR 0 //整数型
#define NOTEST 1 //测试中
#if CHAR
    typedef char ElemType;
    ElemType Nil=' '; //设字符型以空格为空
#else
    typedef int ElemType;
    ElemType Nil=0; //设整型以0为空
#endif

#include <iostream>
#include <fstream> //用于file streams
using namespace std;
#include "../c1.h"
#include "c6-1.h"
#include "bo6-1.cpp"

void visit(ElemType e){
    cout<<e<<' ';
}

int main(){
    Status i;
    int j;
    position p;
    ElemType e;
    SqBiTree T,s;
    InitBiTree(T);
#if NOTEST
    //CreateBiTree(T);
    CreateBiTreeRead(T,"E:\\Users\\cplusDS\\Tree\\main6-1");
    cout<<"建立二叉树后，数为空？"<<BiTreeEmpty(T)<<"(1:是，0：否)"<<endl;
    cout<<"数的深度："<<BiTreeDepth(T)<<endl;
    i=Root(T,e);//获取根节点
    if(i)
        cout<<"二叉树的根为："<<e<<endl;
    else
        cout<<"树空，无根"<<endl;
    cout<<"层序遍历二叉树："<<endl;
    LevelOrderTraverse(T,visit);
    cout<<"中序遍历二叉树："<<endl;
    InOrderTraverse(T,visit);
    cout<<"后序遍历二叉树："<<endl;
    PostOrderTraverse(T,visit);
    cout<<"请输入待修改节点的层号 本层序号: ";
    cin>>p.level>>p.order;
    e=Value(T,p);
    cout<<"待修改节点的原值为："<<e<<" 请输入新值：";
    //cin>>e;
    //Assign(T,p,e);
    cout<<"先序遍历二叉树:"<<endl;
    PreOrderTraverse(T,visit);
    cout<<"节点"<<e<<"的双亲为"<<Parent(T,e)<<",左右孩子分别为";
    cout<<LeftChild(T,e)<<","<<RightChild(T,e)<<",左右兄弟节点分别为：";
    cout<<LeftSibling(T,e)<<","<<RightSibling(T,e)<<endl;
    InitBiTree(s);
    cout<<"建立右子树为空的的树s:"<<endl;
    CreateBiTree(s);
    cout<<"树s插到树T中，请输入树T中树s的双亲节点 s为左（0）或右（1）";
    cin>>e>>j;
    InsertChild(T,e,j,s);
    Print(T);
    cout<<"删除子树，请输入带删除子树根节点的层号 本层序号 左（0）或右（1）子树";
    cin>>p.level>>p.order>>j;
    DeleteChild(T,p,j);
    Print(T);
    ClearBiTree(T);
    cout<<"清除二叉树后，树空否？"<<BiTreeEmpty(T)<<"(1:是 0:否) 树的深度="<<BiTreeDepth(T)<<endl;
    i=Root(T,e);
    if(i)
        cout<<"二叉树的根为： "<<e<<endl;
    else
        cout<<"树空，无根"<<endl;
#else
    CreateBiTreeRead(T,"E:\\Users\\cplusDS\\Tree\\file");
#endif

}


