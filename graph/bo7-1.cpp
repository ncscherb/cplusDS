//bo7-1.cpp 图的数组（邻接矩阵）存储（存储结构由c7-1.h定义）的基本操作（21个）包括算法7.1~7.6
//#include "c7-1.h"

#include <fstream>
#include "c7-1.h"

//初始条件：图G存在，u和G中顶点有相同特征
//操作结果：若G中存在顶点u,则返回该顶点在图中的位置；否则返回-1
int LocateVex(MGraph G,VertexType u){
    int i;
    for(i=0;i<G.vexnum;++i)
        //strcmp为字符串标胶，传入字符串的指针
        if(strcmp(u,G.vexs[i])==0)
            return i;
    return -1;
}

//采用数组（邻接矩阵）表示法，由文件构造没有相关信息的无向图G
void CreateFUDG(MGraph &G, string filename){
    int i,j,k;
    VertexType va,vb;
    ifstream inFile(filename,ios::out);

    if (!inFile.is_open()) {
        printf("Failed to open file: %s\n", filename.c_str());
        exit(ERROR);
    }

    inFile>>G.vexnum; //获取顶点数量
    inFile>>G.arcnum; //边的数量

    for(i=0;i<G.vexnum;i++)//获取顶点向量
        inFile>>G.vexs[i];
    //初始化邻接矩阵
    for(i=0;i<G.vexnum;i++){
        for(j=0;j<G.vexnum;j++){
            G.arcs[i][j].adj=0; //图（查看i和j是否连通）
            G.arcs[i][j].info=NULL; //没有相关信息
        }
    }

    for(k=0;k<G.arcnum;i++){
        inFile>>va>>vb;
        i=LocateVex(G,va);
        j=LocateVex(G,vb);
        G.arcs[i][j].adj=G.arcs[j][i].adj=1; //无向图
    }

    inFile.close();
    G.kind=UDG;
}

//采用数组（邻接矩阵）表示法，由文件构造没有相关信息的无向网G
void CreateFUND(MGraph &G, string filename){
    int i,j,k,w;
    VertexType va,vb;
    ifstream inFile(filename,ios::out);
    if(!inFile.is_open()){
        printf("can not open the file:%s",filename.c_str());
        inFile.close();
        exit(ERROR);
    }
    inFile>>G.vexnum;
    inFile>>G.arcs;
    for(i=0;i<G.vexnum;i++)
        inFile>>G.vexs[i];
    for(i=0;i<G.vexnum;i++)
        for(j=0;j<G.vexnum;j++){
            
        }


}
