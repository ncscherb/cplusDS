//bo7-1.cpp 图的数组（邻接矩阵）存储（存储结构由c7-1.h定义）的基本操作（21个）包括算法7.1~7.6
//#include "c7-1.h"

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

    for(k=0;k<G.arcnum;k++){
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
    inFile>>G.arcnum;
    for(i=0;i<G.vexnum;i++)
        inFile>>G.vexs[i];
    for(i=0;i<G.vexnum;i++)
        for(j=0;j<G.vexnum;j++){
            G.arcs[i][j].adj=INT_MAX; //网-边的权重
            G.arcs[i][j].info=NULL; //没有相关信息
        }
    for(k=0;k<G.arcnum;++k){
       inFile>>va>>vb>>w;
        i=LocateVex(G,va);
        j=LocateVex(G,vb);
        G.arcs[i][j].adj=G.arcs[j][i].adj=w; //无向网-添加权重
    }
    inFile.close(); //关闭数据文件
    G.kind=UDN;
}

//采用数组（邻接矩阵）表示法，由文件构造有相关信息的有向网G
void CreateFDG(MGraph &G, string filename){
    int i,j,k,l,IncInfo;
    char s[MAX_INFO];
    VertexType va,vb;
    ifstream inFile(filename,ios::out);
    if(!inFile.is_open()){
        printf("can not open the file:%s",filename.c_str());
        inFile.close();
        exit(ERROR);
    }
    inFile>>G.vexnum;
    inFile>>G.arcnum;
    //构造顶点向量
    for(i=0;i<G.vexnum;i++)
        inFile>>G.vexs[i];
    //初始化邻接矩阵
    for(i=0;i<G.vexnum;i++)
        for(j=0;j<G.vexnum;j++){
            G.arcs[i][j].adj=0; //图
            G.arcs[i][j].info=NULL; //没有相关信息
        }
    //构造弧信息
    for(k=0;k<G.arcnum;++k){
         //文本中的三个值，前两个为节点，第三个为边的信息
        inFile>>va>>vb>>s;
        i=LocateVex(G,va);
        j=LocateVex(G,vb);
        G.arcs[i][j].adj=1; //有向图
        //边的信息不为空时
        l=strlen(s);
        if(l){
            //有向图
            G.arcs[i][j].info=(char *)malloc((l+1)*sizeof(char));
            strcpy(G.arcs[i][j].info,s); //复制值
        }
    }
    inFile.close(); //关闭数据文件
    G.kind=DG;
}

//采用数据（邻接矩阵）表示法，构造图G。算法7.1改
void CreateFGraph(MGraph &G,string filename){
    printf("请输入图G的类型（有向图：0，有向网：1，无向图：2，无向网：3）：");
    scanf("%d",&G.kind);
    switch (G.kind){
        case DG: //构造有向图
            CreateFDG(G,filename);
            break;
        case DN:
            break;
        case UDG: //构造无向图
            CreateFUDG(G,filename);
            break;
        case UDN: //构造无向网
            CreateFGraph(G,filename);
            break;
    }
}

//销毁图
void DestoryGraph(MGraph &G){
    int i,j,k=0;
    if(G.kind%2)  //网-即带权的图
        k=INT_MAX;  //k为两顶点之间无边或弧是邻接矩阵元素的值
    for(i=0;i<G.vexnum;i++) //释放弧或边的相关信息（如果有的话）
        if(G.kind<2) //有向
        {
            for(j=0;j<G.vexnum;j++){
                if(G.arcs[i][j].adj!=k){ //有弧
                    if(G.arcs[i][j].info) //有相关信息
                    {
                        free(G.arcs[i][j].info);
                        G.arcs[i][j].info=NULL;
                    }
                }

            }
        }else{ //无向
            for(j=i+1;j<G.vexnum;j++){//只查上三角
                if(G.arcs[i][j].adj!=k)//有边
                    if(G.arcs[i][j].info){ //有相关信息
                        free(G.arcs[i][j].info);
                        G.arcs[i][j].info=G.arcs[j][i].info=NULL;
                    }
            }
        }
    G.vexnum=0; //定点数为0
    G.arcnum=0; //边数为0
}

//v是G中某个顶点的序号
//返回v的值
VertexType& GetVex(MGraph G,int v){
    if(v>G.vexnum||v<0)
        exit(ERROR);
    return G.vexs[v];
}

//v是G中某个顶点,对v赋新值value
Status PutVex(MGraph &G,VertexType v,VertexType value){
    int k;
    k=LocateVex(G,v);
    if(k<0)
        return ERROR;
    strcpy(G.vexs[k],value);
    return OK;
}

//v是G中某个顶点，返回v的第一个邻接顶点序号。若顶点在G中没有邻接顶点，则返回-1
int FirstAdjVex(MGraph G,VertexType v){
    int i,j=0,k;
    k=LocateVex(G,v);
    if(G.kind%2) //网
        j=INT_MAX;
    for(i=0;i<G.vexnum;i++){ //找到第一个顶点
        if(G.arcs[k][i].adj!=j)
            return i;
    }

    return -1;
}

//v是G中某个顶点，w是v的邻接顶点
//返回v的（相对于w的）下一个邻接顶点的序号，若w是v的最后一个邻接顶点，则返回-1
int NextAdjVex(MGraph G,VertexType v,VertexType w){
    int i,k=0,v1,v2;
    v1=LocateVex(G,v);
    v2=LocateVex(G,w);
    if(G.kind%2)
        k=INT_MAX;
    for(i=v2+1;i<G.vexnum;i++){
        if(G.arcs[v1][i].adj!=k)
            return i;
    }

    return -1;
}

//v和图G中顶点有相同特征
//在图G中增添新顶点v(不增添与顶点相关的弧，留待InsertArc()去做）
void InsertVex(MGraph &G,VertexType v){
    int i,j=0;
    if(G.kind%2)//如果是有向图
        j=INT_MAX;
    strcpy(G.vexs[G.vexnum],v); //构造新的顶点向量
    for(i=0;i<=G.vexnum;i++){
        G.arcs[G.vexnum][i].adj=G.arcs[i][G.vexnum].adj=j;
        //初始化新增行、新增列邻接矩阵的值（无边或弧）
        G.arcs[G.vexnum][i].info=G.arcs[i][G.vexnum].info=NULL; //初始化相关信息指针
    }

    G.vexnum++;
}

//v是G中某个顶点，删除G中顶点v及其相关的弧
Status DeleteVex(MGraph &G,VertexType v){
   int i,j,k,m=0;
    if(G.kind%2)
        m=INT_MAX;
    k=LocateVex(G,v);
    if(k<0)
        return ERROR; //v不是G的顶点
    //有入弧或边
    for(i=0;i<G.vexnum;i++){
       if(G.arcs[i][k].adj!=m){
           if(G.arcs[i][k].info) //有相关信息
               free(G.arcs[i][k].info); //释放相关信息
           G.arcnum--; //弧的边数减一
       }
    }

    //如果是有向图
    if(G.kind<0)
        for(i=0;i<G.vexnum;i++){ //如果有出弧或边
            if(G.arcs[k][i].adj!=m){
                if(G.arcs[k][i].info){
                    free(G.arcs[k][i].info);
                }
                G.arcnum--;
            }
        }

    for(i=0;i<G.vexnum;i++){
        for(j=0;j<G.vexnum;j++){
           if(i>k&j<k){
               G.arcs[i-1][j].adj=G.arcs[i][j].adj;
               G.arcs[i-1][j].info=G.arcs[i][j].info;
           }else if(i<k&j>k){
                G.arcs[i][j-1].adj=G.arcs[i][j].adj;
                G.arcs[i][j-1].info=G.arcs[i][j].info;
           }else if(i>k&j>k){
               G.arcs[i-1][j-1].adj=G.arcs[i][j].adj;
               G.arcs[i-1][j-1].info=G.arcs[i][j].info;
           }
        }
    }

    //序号k后面的顶点向量依次前移
    for(i=k+1;i<G.vexnum;i++)
        strcpy(G.vexs[i-1],G.vexs[i]);

    G.vexnum--; //更新图的顶点数
    return OK;
}

//v和w是G中两个顶点，在G总增加弧<v,w>，若G是无向的，则还增添对称<w,v>
Status InsertArc(MGraph &G,VertexType v,VertexType w){
    int i,l,v1,w1;
    char s[MAX_INFO];
    v1=LocateVex(G,v); //头
    w1=LocateVex(G,w); //尾

    if(v1<0 || w1<0)
        return ERROR;
    G.arcnum++;
    if(G.kind%2) //如果是网
    {
        printf("请输入此弧或边的权值：");
        scanf("%d",&G.arcs[v1][w1].adj);
    } else //图
        G.arcs[v1][w1].adj=1;

    printf("是否有该弧或边的相关信息(0:无 1:有)：");
    scanf("%d%*c",&i); //%*c吃掉回车
    if(i){
        printf("请输入该弧或边的相关信息(<%d个字符)：",MAX_INFO);
        gets(s);
        l=strlen(s);
        if(l){
            G.arcs[v1][w1].info=(char*)malloc((l+1)*sizeof(char));
            strcpy(G.arcs[v1][w1].info,s);
        }
    }

    if(G.kind>1){//无向
        G.arcs[w1][v1].adj=G.arcs[v1][w1].adj;
        G.arcs[w1][v1].info=G.arcs[v1][w1].info;//指向同一个相关信息
    }

    return OK;
}

//v和w是G中两个顶点，在G中删除弧<v,w>，若G是无向的，则还删除对称弧<w,v>
Status DeleteArc(MGraph &G,VertexType v,VertexType w){
    int v1,w1,j=0;
    if(G.kind%2)
        j=INT_MAX;
    v1=LocateVex(G,v);
    w1=LocateVex(G,w);
    if(v1<0||w1<0)
        return ERROR;
    G.arcs[v1][w1].adj=j;
    if(G.arcs[v1][w1].info){//有其他信息
        free(G.arcs[v1][w1].info);
        G.arcs[v1][w1].info=NULL;
    }
    if(G.kind>=2){//无向，删除对称弧<w,v>
        G.arcs[w1][v1].adj=j;
        if(G.arcs[w1][v1].info){
            free(G.arcs[w1][v1].info);
            G.arcs[w1][v1].info=NULL;
        }
    }
    G.arcnum--;
    return OK;
}

Boolean visited[MAX_VERTEX_NUM]; //访问标志数组（全局变量）
void(*VisitFunc)(VertexType); //函数变量

//从第v(v是顶点序号)个顶点出发递归第深度优先遍历图G，算法7.5
//从第一个顶点访问第二个，再访问第三个
void DFS(MGraph G,int v){
    int w;
    visited[v]=TRUE; //设置访问标标志为TRUE（已访问）
    VisitFunc(G.vexs[v]); //访问第v个顶点

    for(w=FirstAdjVex(G,G.vexs[v]);w>=0;w=NextAdjVex(G,G.vexs[v],G.vexs[w]))
        if(!visited[w])
            DFS(G,w); //对v的尚未访问的序号为w的邻接顶点递归调用DFS
}

//图G存在，Visit是顶点的应用。算法7.4
//操作结果:从第一个顶点其，深度优先遍历图G，并对每个顶点调用函数visit一个，且仅一次
void DFSTraverse(MGraph G,void(*Visit)(VertexType)){
    int v;
    //使用全局变量VisitFunc，使DFS不必设函数指针参数
    VisitFunc=Visit;
    for(v=0;v<G.vexnum;v++)
        visited[v]=FALSE; //访问标志数组初始化（未被访问）
    for(v=0;v<G.vexnum;v++)//可以遍历孤立点
        if(!visited[v])
            DFS(G,v); //对尚未访问的顶点v调用DFS
    printf("\n");
}

typedef VRType QElemType; //队列元素类型
#include "../stack&queue/c3-2.h"
#include "../stack&queue/bo3-2.cpp"

//从第一个顶点起，按广度优先非递归遍历图G，并对每个顶点调用一次visit函数，且一次
void BFSTraverse(MGraph G,void(*Visit)(VertexType)){
    int i,v,w;
    LinkQueue q; //使用辅助队列Q和访问标志数组visited
    InitQueue(q); //置空的辅助队列Q
    for(i=0;i<G.vexnum;i++)
        visited[i]=FALSE; //置初值
    for(i=0;i<G.vexnum;i++)
        if(!visited[i]){//v尚未访问
            EnQueue(q,i);
            Visit(G.vexs[i]);
            visited[i]=TRUE;
            while(!QueueEmpty(q)){
                DeQueue(q,v);
                for(w=FirstAdjVex(G,G.vexs[v]);w>=0;w=NextAdjVex(G,G.vexs[v],G.vexs[w])){
                    if(!visited[w]){
                        Visit(G.vexs[w]);
                        visited[w]=TRUE;
                        EnQueue(q,w);
                    }
                }
            }

        }
    printf("\n");
}

//输出邻接矩阵存储表示的图G
void Display(MGraph G){
    int i,j;
    char s[7];
    switch(G.kind){
        case DG: strcpy(s,"有向图");
            break;
        case DN: strcpy(s,"有向网");
            break;
        case UDG: strcpy(s,"无向图");
            break;
        case UDN: strcpy(s,"无向网");
            break;
    }

    printf("%d个顶点%d条边或弧的%s。顶点依次是：",G.vexnum,G.arcnum,s);
    for(i=0;i<G.vexnum;i++)
        printf("%s ",G.vexs[i]);

    printf("\nG.arcs.adj:\n");
    for(i=0;i<G.vexnum;i++)
        printf("%11s",G.vexs[i]);
    printf("\n");
    for(i=0;i<G.vexnum;i++){
        printf("%s",G.vexs[i]);
        for(j=0;j<G.vexnum;j++)
            printf("%11d",G.arcs[i][j].adj);
        printf("\n");
    }

    printf("G.arcs.info:\n");//输出G.arcs.info
    printf("顶点1（弧尾） 顶点2（弧头） 该边或弧的信息：\n");
    for(i=0;i<G.vexnum;i++){
        if(G.kind<2){//有向
            for(j=0;j<G.vexnum;j++)
                if(G.arcs[i][j].info)
                    printf("%5s %11s     %s\n",G.vexs[i],G.vexs[j],G.arcs[i][j].info);
        }else{ //无向，输出上三角
            for(j=i+1;j<G.vexnum;j++){
                if(G.arcs[i][j].info)
                    printf("%5s %11s     %s\n",G.vexs[i],G.vexs[j],G.arcs[i][j].info);

            }
        }
    }
}

