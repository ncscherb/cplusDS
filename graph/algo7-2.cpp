//最小生成树-实现算法7.9的程序-algo7-2.cpp程序
#include "../c1.h"
#include <fstream>
using namespace std;
typedef int VRType;
typedef char InfoType;
#define MAX_NAME 3 //顶点字符串的最大长度+1
#define MAX_INFO 20 //相关信息字符串的最大长度+1
//typedef char VertexType[MAX_NAME];
#include "c7-1.h"
#include "bo7-1.cpp"

//记录从顶点集U到V-U的代价最小的边的辅助数组定义
typedef struct{
    VertexType adjvex;
    VRType lowcost;
}minside[MAX_VERTEX_NUM];

//求sz.lowcost的最小正值，并返回其在sz中的序号
//函数参数信息：sz[j].lowcost=>存储与k相邻的顶点所有边的权重
//sz[j].adjvex=>存储定k个顶点
int minimum(minside sz,MGraph G){
    int i=0,j,k,min=0;
    //lowcost为零的顶点表示已经访问过了
    while (!sz[i].lowcost)
        i++;

    min=sz[i].lowcost;
    k=i; //k用来保存最小值对应的顶点序号
    for(j=i+1;j<G.vexnum;j++){
       if(min>sz[j].lowcost && sz[j].lowcost>0){
           min=sz[j].lowcost;
           k=j;
       }
    }

    return k;

}

//用普里姆算法从第u个顶点出发构造网G的最小生成树，输出T的各条边
void MiniSpanTree_PRIM(MGraph G, VertexType u){
    int i,j,k;
    minside closedge;
    k=LocateVex(G,u); //返回顶点u在数组中的序号
    //辅助数组初始化
    for(j=0;j<G.vexnum;++j){
        strcpy(closedge[j].adjvex,u);
        //保存顶点u到与其相邻的各个顶点的最小值
        closedge[j].lowcost=G.arcs[k][j].adj;
    }
    //用0标记已访问过的顶点
    closedge[k].lowcost=0; //初始,U={u}
    printf("最小代价生成树的各条边为：\n");
    //选择其余G.vexnum-1个顶点
    for(i=1;i<G.vexnum;++i){
        //求出T的下一个节点：第k个顶点（找到与该顶点相邻的顶点边的最小值，返回该顶点的序号）
        k=minimum(closedge,G);
        printf("(%s-%s)\n",closedge[k].adjvex,G.vexs[k]);
        //将第k顶点并入u集
        closedge[k].lowcost=0;

        //构造与顶点k相邻的边和顶点信息
        for(j=0;j<G.vexnum;j++){
            if(G.arcs[k][j].adj<closedge[j].lowcost){
            //if(closedge[j].lowcost!=0){-->该种方法未考虑不能联通情况
                strcpy(closedge[j].adjvex,G.vexs[k]);
                closedge[j].lowcost=G.arcs[k][j].adj;
            }
        }
    }

}

int main(){
    MGraph g;
    CreateFUND(g,"E:\\Users\\cplusDS\\graph\\algo7-2.txt"); //构造无向网--一定是连通的
    Display(g);//输出图
    //用普里姆算法从g的第1个顶点出发，输出最小生成树的各条边
    MiniSpanTree_PRIM(g,g.vexs[0]);

}

