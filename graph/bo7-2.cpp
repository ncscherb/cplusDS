//bo7-2.cpp 图的邻接表存储（存储结构由c7-21.h定义）的基本操作（15个），包括算法7.4~7.6
#include "../linear/func2-1.cpp"

#include <fstream>
using std;

//若G中存在顶点u,则放回该顶点在图中位置；否则返回-1
int LocateVex(ALGrap G,VertexType u){
    int i;
    for(i=0;i<G.vertices[i];++i){
        if(strcmp(u,G.vertices[i].data)=0){
            return i;
        }
    }

    return -1;
}

//采用邻接表存储结构，由文件构造没有相关信息图或网G（一个函数
// 构造四种图）
void CreateGraphF(ALGraph &G){
    int i,j,k,w; //w是权值
    VertexType va,vb;
    ElemType e;
    char filename[13];

    filename="bo7-2.txt";
    ifstream inFile{filename};
    inFile>>G.kind;
    inFile>>G.vexnum;
    inFile>>G.arcnum;

    //构造顶点向量
    for(i=0;i<G.vexnum;++i){
        inFile>>G.vertices[i].data;
        G.vertices[i].firstarc=NULL; //初始化与该顶点相关的出弧链表
    }

    //构造相关弧链表
    for(k=0;k<G.arcnum;++k){
        if(G.kind%2)//网
            inFile>>va>>vb>>w;
        else// 图
            inFile>>va>>vb;
        i=LocateVex(G,va); //弧尾
        j=LocateVex(G,vb); //弧头
        e.info=NULL; //给待插入表节点e赋值，图无权
        e.adjvex=j;
        if(G.kind%2){//网
            e.info=(int *)malloc(sizeof(int)); //动态生成存放权值的空间
            *(e.info)=w;//info存储权值信息
        }
        ListInsert(G.vertices[i].firstarc,1,e);
        if(G.kind>=2){ //无向图或网，产生第二个表节点，并插在第j个元素(入弧)的表头
            e.adjvex=i; //e.info不变，不必再赋值
            ListInsert(G.vertices[j].firstarc,1,e);//插在第j个元素的表头，在bo2-8.cpp
        }
    }
}