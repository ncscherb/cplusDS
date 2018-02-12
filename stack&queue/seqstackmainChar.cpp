typedef char ElemType ;
#include "../c1.h"
#include <fstream> //引入读写文件头文件
using namespace std;
#include "seqstack.cpp"
#include "../func2-3.cpp"
#include "seqstackEx.cpp"

int main(){
    SeqStack s;
    ElemType e;

    cout<<"十六进制转换:";
    //check();

    cout<<"编辑器：";
    //由内存向编辑器写入文件类ofstream
    //等价于ofstream outFile("ed.txt",ios::out)
    ofstream outFile{"ed.txt"};

    if(outFile.is_open()){
        lineEdit(outFile);
        outFile.close(); //关闭fp所指的文件
    }else{
        printf("创建行编辑器失败\n");
    }
}