//main6-1.cpp 检验bo6-1.cpp的主程序，利用条件编译选择数据类型为char或int
// #define CHAR 1 //字符型
#define CHAR 0 //整数型
#if CHAR
    typedef char ElemType;
    ElemType Nil=' '; //设字符型以空格为空
#else
    typedef int ElemType;
    ElemType Nil=0; //设整型以0为空
#endif

#include <iostream>
using namespace std;
#include "../c1.h"
#include "c6-1.h"
#include "bo6-1.cpp"

int main(){
    SqBiTree T,s;
    InitBiTree(T);
    CreateBiTree(T);
    cout<<"建立二叉树后，数为空？"<<BiTreeEmpty(T)<<"(1:是，0：否)"<<endl;
    cout<<"数的深度："<<BiTreeDepth(T)<<endl;
}


