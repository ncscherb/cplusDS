//main7-2.cpp 检验bo7-2.cpp主程序
#include "../c1.h"
#include <fstream>
using namespace std;
#define MAX_NAME 3 //顶点字符串的最大长度+1
typedef int InfoType; //网络的圈子类型
typedef char VertexType[MAX_NAME]; //顶点类型为字符串
#include "c7-21.h"
#include "bo7-2.cpp"

void print(char *i){
    printf("%s ",i);
}

int main(){
    int i,j,k,n;
    ALGraph g;
    VertexType v1,v2;
    CreateGraphF(g);
    Display(g);
    printf("插入新顶点，请输入顶点的值：");
    scanf("%s",v1);
    InsertVex(g,v1);
    printf("插入与新顶点有关的边或弧，请输入弧或边数：");
    scanf("%d",&n);
    for(k=0;k<n;k++){
        printf("请输入另一顶点的值：");
        scanf("%s",v2);
        if(g.kind<=1){
            printf("对于有向图或网，请输入另一顶点的方向（0：弧头 1：弧尾）");
            scanf("%d",&j);
        }
        if(j)
            InsertArc(g,v2,v1);
        else
            InsertArc(g,v1,v2);
    }
    Display(g);

}