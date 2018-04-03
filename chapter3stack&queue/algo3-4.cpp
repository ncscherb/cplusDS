typedef int SElemType;
#include "../c1.h"
#include "c3-1.h"
#include "bo3-1.cpp"
//------------algo3-4------------
//行编辑器:#退回一格，@清空已输入的当前行
void lineEdit(ofstream &outFile){
    //利用字符栈s，从终端接受一行并送至调用过程的数据区域
    SeqStack s;
    char ch,pp;
    InitStack(s);

    printf("请输入一个文本文件，^Z结束输入：\n");
    ch=getchar(); //getchar--依次从屏幕获取一个字符，赋值给ch,如果输入多个，会连续不断的获取
    while(ch!=EOF ){
        //当全文没有结束，eof为^z/ctr+d键，全文结束--则获取该行输入的所有字符
        //当全文没有结束且没有到行末（不是换行符）
        while(ch!=EOF && ch!='\n'){
            switch (ch){
                case '#': //仅当栈非空是退栈
                    if(!StackEmpty)
                        Pop(s,pp);
                    break;
                case '@': //重置s为空栈
                    ClearStack(s);
                    break;
                default:
                    Push(s,ch); //其他字符进栈
            }
            ch=getchar();
        }

        //StackTraverse(s,printch);
        while(s.base<s.top){ //将栈中的文本写入到文本中
            outFile<<*s.base++;
        }
        outFile<<"\n"; //输入一个换行符
        outFile.flush(); //刷新输出文本内容

        ClearStack(s);//重置s为空栈
        if(ch!=EOF){
            ch=getchar();
        }
    }
    DestoryStack(s);
}

int main(){
    lineEdit();
}
