//c7-21.h 图的邻接表存储表示（与单链表的变量类型建立联系）
#define MAX_VERTEX_NUM 20
enum GraphKind{DG=0,DN=1,UDG=2,UDN=3};//{有向图，有向网，无向图，无向网}
struct ElemType{ //加
    int adjvex; //该弧指向的顶点位置
    InfoType *info; //网的权值指针
};

//表节点
struct ArcNode{ //改
    ElemType data; //除指针以外的部分都属于ElemType
    ArcNode *nextarc; //指向下一条弧的指针
};

typedef struct {
    VertexType data; //顶点信息
    ArcNode *firstarc; //第一个表节点的地址，指向第一条依附该顶点的的弧的指针
}VNode,AdjList[MAX_VERTEX_NUM]; //头结点

struct ALGraph{
    AdjList vertices;
    int vexnum,arcnum; //图的当前顶点数和弧数
    GraphKind kind; //图的种类标志
};

//加，定义单链表的节点类型是图的表节点的类型
#define LNode ArcNode
//加，定义单链表节点的指针域是表节点指向下一条弧的指针域
#define next nextarc
//加，定义指向单链表节点的指针是指向图的表节点的指针
typedef ArcNode *LinkList;
