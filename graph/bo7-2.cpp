//bo7-2.cpp 图的邻接表存储（存储结构由c7-21.h定义）的基本操作（15个），包括算法7.4~7.6
#include "../linear/func2-1.cpp"

//若G中存在顶点u,则放回该顶点在图中位置；否则返回-1
int LocateVex(ALGraph G,VertexType u){
    int i;
    for(i=0;i<G.vexnum;++i){
        if(strcmp(u,G.vertices[i].data)==0){
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
    string filename;

    filename="E:\\Users\\cplusDS\\graph\\bo7-2.txt";
    ifstream inFile(filename,ios::out);
    if (!inFile.is_open()) {
        printf("Failed to open main6-1: %s\n", filename.c_str());
        exit(ERROR);
    }
    inFile>>i; //选择图的种类:图的类型(有向图:0,有向网:1,无向图:2,无向网:3)
    G.kind=(GraphKind)i; //强制类型转换
    inFile>>G.vexnum; //顶点数量
    inFile>>G.arcnum; //弧的数量

    //构造顶点向量
    for(i=0;i<G.vexnum;++i){
        inFile>>G.vertices[i].data; //顶点的值
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
    inFile.close();
}

//销毁图G
void DestoryGraph(ALGraph &G){
    int i;
    ElemType e;
    for(i=0;i<G.vexnum;i++){ //对所有顶点
        if(G.kind%2){ //网
            while(G.vertices[i].firstarc){
                ListDelete(G.vertices[i].firstarc,1,e); //删除链表的第一个节点，并将值赋给e
                if(e.adjvex>i) //顶点序号>i(保证动态生成的权值空间只释放一次)
                    free(e.info); //用e.info存储边的权值信息
            }
        } else{ //图
            DestoryList(G.vertices[i].firstarc);
        }
    }

    G.vexnum=0;//顶点数为0
    G.arcnum=0;//边或弧数为0
}


//v是G中某个顶点的序号，返回v的值
VertexType& GetVex(ALGraph G,int v){
    if(v>=G.vexnum||v<0)
        exit(ERROR);
    return G.vertices[v].data;
}

//图G存在，v是G中某个顶点，对v赋新值value
Status PutVex(ALGraph &G,VertexType v,VertexType value){
    int i;
    i=LocateVex(G,v);
    if(i>-1){
        strcpy(G.vertices[i].data,value);
        return OK;
    }

    return ERROR;
}

//返回v的第一个邻接顶点的序号，若顶点G中没有邻接顶点，则返回-1
int FirstAdjVex(ALGraph G,VertexType v){
    int i;
    ArcNode *p;
    i=LocateVex(G,v);
    p=G.vertices[i].firstarc;
    if(p)
        return p->data.adjvex;
    else
        return -1;
}

//判断两个弧指向的值是否相同
Status equalvex(ElemType a,ElemType b){
    if(a.adjvex==b.adjvex)
        return OK;
    else
        return ERROR;
}

//返回v的（相对于w的)下一个邻接顶点的序号，若w是v的最后一个顶点，则返回-1
//v和w分别是顶点的值
int NextAdjVex(ALGraph G,VertexType v,VertexType w){
    LinkList p,p1; //p1在Point()中用作辅助指针，Point()在func2-1.cpp中
    ElemType e;
    int v1;
    v1=LocateVex(G,v);  //查找v的存储位置
    e.adjvex=LocateVex(G,w); //查找w的存储位置
    //p指向顶点v的链表中邻接顶点为w的节点
    p=Point(G.vertices[v1].firstarc,e,equalvex,p1);
    if(!p||!p->nextarc)
        return -1;
    else
        return p->nextarc->data.adjvex;//返回v的（相对于w的)下一个邻接顶点
}

//在图G中增添新顶点v(不增添与顶点相关的弧，留待InsertArc()去做
void InsertVex(ALGraph &G,VertexType v){
    strcpy(G.vertices[G.vexnum].data,v); //构造新的顶点向量
    G.vertices[G.vexnum].firstarc=NULL;
    G.vexnum++; //顶点数量+1
}

//删除G中顶点v及其相关的弧
Status DeleteVex(ALGraph &G,VertexType v){
    int i,j,k;
    ElemType e;
    LinkList p,p1;

    j=LocateVex(G,v); //v顶点的位置
    i=ListLength(G.vertices[j].firstarc); //以j为节点的出弧和入弧的个数
    //删除顶点v相关的边
    /*
     * 1.找到删除顶点的位置
     * 2.删除该顶点所有相关的边，如果是网还要删除权重-边数减少
     * 3.删除该顶点--后面顶点依次前移，顶点数减1
     * 3.删除其他顶点指向该顶点的边
     * 4.该顶点之后的顶点的位置向前移动一个
     */
    //如果是网，还要删除权重
    if(G.kind%2){
        for(k=0;k<i;k++){
            ListDelete(G.vertices[i].firstarc,1,e);
            free(e.info);
        }
    }else{
        DestoryList(G.vertices[i].firstarc);
    }
    G.arcnum-=i;

    for(k=i;k<G.vexnum;k++)
        strcpy(G.vertices[i-1].data,G.vertices[i].data);
    G.vexnum--;

    //1.注意判断是否是有向图--边减1
    //2.判断四否是有权重--释放权重
    for(i=0;i<G.vexnum;i++){
        e.adjvex=j;
        p=Point(G.vertices[i].firstarc,e,equalvex,p1);
        if(p){//如果找到该节点
            if(p1)
                p1->nextarc=p->nextarc;
            else
                G.vertices[i].firstarc=p->nextarc;
            if(G.kind%2)
                free(p->data.info);
             if(G.kind<2) //有向图
                 G.arcnum--;
        }
        free(p);

        //对于adjvex域,节点序号>j的节点，其序号-1
        for(k=j+1;k<G.vexnum;k++){
            e.adjvex=k;
            p=Point(G.vertices[i].firstarc,e,equalvex,p1);
            if(p)
                p->data.adjvex--;
        }
    }

    return OK;
}

//在G中增添弧<v,w>,若G是无向的，则还增添对称弧
Status InsertArc(ALGraph &G,VertexType v,VertexType w){
    int i,j,k;
    ElemType e;
    ArcNode *p;

    i=LocateVex(G,v);
    j=LocateVex(G,w);
    if(i<0||j<0)
        return ERROR;

    e.adjvex=j;
    e.info=NULL;
    G.arcnum++;

    if(G.kind%2){//网
        e.info=(InfoType *)malloc(sizeof(InfoType));

        printf("请输入边或弧%s->%s的权值：",v,w);
        scanf("%d",e.info);
    }
    ListInsert(G.vertices[i].firstarc,1,e);

    if(G.kind>1){//无向，还要插入对边
        e.adjvex=i;
        ListInsert(G.vertices[j].firstarc,1,e);
    }
    return OK;
}

//在G中删除弧<v,w>，若G是无向的，则还要删除对称弧
Status DeleteArc(ALGraph &G,VertexType v,VertexType w){
    int i,j;
    ElemType e;
    Status k;

    i=LocateVex(G,v);
    j=LocateVex(G,w);

    if(i<0||j<0||i==j)
        return ERROR;

    e.adjvex=j;

    k=DeleteElem(G.vertices[i],e,equalvex); //删除的元素由e返回
    if(k){
        G.arcnum--;
        if(G.kind%2) //网
            free(e.info);
        if(G.kind>=2){
            e.adjvex=i;
            DeleteElem(G.vertices[j].firstarc,e,equalvex);

            if(G.kind%2)
                free(e.info);
        }
        return OK;
    } else //没有找到待删除的弧
        return ERROR;
}

Boolean visited[MAX_VERTEX_NUM];//访问标志数组（全局变量）
void(*VisitFunc)(char* v); //函数全局变量
//深度优先遍历--从第v个顶点出发递归地深度优先遍历图G
vlid DFS(ALGraph G,int v){
    int i;
    VisitFunc(G.vertices[v].data);
    for(i=FirstAdjVex(G,G.vertices[v].data);i>=0;i=NextAdjVex(G,G.vertices[v].data,G.vertices[i].data)){
        if(!visited[i])
            DFS(G,i); //对未访问的节点递归调用dfs
    }
}

//对图G作深度优先遍历-调用DFS
void DFSTraverse(ALGraph G,void(*Visit)(char*)){
    int i;

    VisitFunc=Visit;
    for(i=0;i<G.vexnum;i++)
        visited[i]=FALSE;

    for(i=0;i<G.vexnum;i++){
        if(!visited[i]){
            DFS(G,i);
        }
    }
    printf("\n");
}

typedef int QElemType;
#include "../stack&queue/c3-2.h"
#include "../stack&queue/b3-2.cpp"
//按广度优先非递归遍历图G。使用辅助队列Q和访问标志数组visited
void BFSTraverse(ALGraph G,void(*Visit)(char *)){
    int i,v,w;
    LinkQueue q;
    InitQueue(q);

    for(i=0;i<G.vexnum;i++)
        visited[i]=FALSE;

    for(i=0;i<G.vexnum;i++){
        if(!visited[i]){
            EnQueue(q,i);
            Visit(G.vertices[i].data);
            visited[v]=TRUE;

            while (!EmptyQueue(q)){
                v=DeQueue(q);
                for(w=FirstAdjVex(G,G.vertices[v].data);w>-1;w=NextAdjVex(G,G.vertices[v].data,G.vertices[w].data)){
                    if(!visited[w]){
                        Visit(G.vertices[w].data);
                        visited[w]=TRUE;
                        EnQueue(q,w);
                    }
                }
            }
        }
    }
    printf("\n");

}

//输出图的邻接矩阵
void Display(ALGraph G){
    int i;
    ArcNode *p;

    switch (G.kind){
        case DG:
           printf("有向图\n") ;
            break;
        case DN:
            printf("有向网\n");
            break;
        case UDN:
            printf("无向图\n");
            break;
        case UDG:
            printf("无向网\n");
            break;
    }

    printf("%d个顶点：",G.vexnum);
    for(i=0;i<G.vexnum;i++)
        printf(" %s",G.vertices[i].data);
    printf("\n%d条边\n",G.arcnum);

    for(i=0;i<G.vexnum;i++){
        p=G.vertices[i].firstarc;
        while (p){
            if(G.kind<=1 || i<p->data.adjvex){ //有向或者无向的两次中的一次
                printf("%s->%s",G.vertices[i].data,G.vertices[p->data.adjvex].data);
                if(G.kind%2)
                    printf(":%d ",*p->data.info);
            }
            p=p->nextarc;
        }
        printf("\n");
    }
}