//main7-1.cpp 检验bo7-1.cpp的主程序
#include "../c1.h"
#include <fstream>
using namespace std; //注：string ifstream等都要使用std命名空间->注意std的位置
#define MAX_NAME 5 //顶点字符串的最大长度+1
#define  MAX_INFO 20//相关信息字符串最大长度+1
#include "c7-1.h"
#include "bo7-1.cpp"

void visit(VertexType i){
    printf("%s ",i);
}

int main(){
    int i,j,k,n;
    MGraph g;
    VertexType v1,v2;
    //构造图
    CreateFUDG(g,"E:\\Users\\cplusDS\\graph\\F7-1.TXT");
    Display(g); //输出图g
    printf("深度优先遍历：");
    DFSTraverse(g,visit);
    printf("广度优先遍历：");
    //BFSTraverse(g,visit);
    printf("\n***********************\n");
    printf("插入新顶点，请输入顶点的值：");
    scanf("%s",v1);
    InsertVex(g,v1);
    printf("插入与新顶点有关的弧或边，请输入弧或边数：");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("请输入第%d条边另一顶点的值：",i+1);
        scanf("%s",v2);
        if(g.kind<=1){
            printf("对于有向图或网，请输入另一顶点的方向（0：弧头 1：弧尾）");
            scanf("%d",&j);
            if(j) //v2是弧尾
                InsertArc(g,v2,v1);
            else //v2是弧头
                InsertArc(g,v1,v2);
        } else{
            InsertArc(g,v1,v2);
        }
    }
    Display(g);
    printf("深度优先遍历：");
    DFSTraverse(g,visit);
    printf("广度优先遍历：");
    BFSTraverse(g,visit);
    printf("\n***********************\n");
    //DeleteVex(g,"b");

}

