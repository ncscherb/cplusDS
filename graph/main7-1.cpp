//main7-1.cpp 检验bo7-1.cpp的主程序
#include "../c1.h"
#include <fstream>
using namespace std; //注：string ifstream等都要使用std命名空间->注意std的位置
#define MAX_NAME 5 //顶点字符串的最大长度+1
#define  MAX_INFO //相关信息字符串最大长度+1
#include "c7-1.h"
#include "bo7-1.cpp"

void visit(VertexType i){
    printf("%s ",i);
}

int main(){
    int i,j,k;
    MGraph g;
    VertexType v1,v2;
    CreateFUDG(g,"E:\\Users\\cplusDS\\graph\\F7-1.TXT");

}

