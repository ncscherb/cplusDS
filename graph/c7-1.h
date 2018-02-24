//c7-1.h 图的数组（邻接矩阵）存储表示
//#define INFINITY INT_MAX //用整型最大值代替无穷
#define MAX_VERTEX_NUM 26 //最大顶点个数

typedef int VRType; //顶点关系类型
typedef char InfoType; //相关信息类型
typedef char VertexType[5]; //顶点类型
//有向图，有向网，无向图，无向网
enum GraphKind{DG,DN,UDG,UDN};

//图的节点
typedef struct {
    //顶点类型。对无权图，用1（是）或0（否）表示邻接否，对于带权图，用权值表示
    VRType adj;
    InfoType *info; //该弧相关信息的指针（可无）
}ArcCell,AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM]; //二维数组

//图本身
struct MGraph{
    VertexType vexs[MAX_VERTEX_NUM]; //顶点向量
    AdjMatrix arcs; //邻接矩阵
    int vexnum,arcnum; //图的当前顶点数和弧数
    GraphKind kind; //图的种类标志
};