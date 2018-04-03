//main2-8.cpp 检验bo2-8.cpp和bo2-9.cpp的主程序
#include "../c1.h"
typedef int ElemType;
#include "c2-2.h"
#include "bo2-8.cpp"
#include "func2-3.cpp"
#include "func2-1.cpp"

int main(){
    LinkList L,p;
    ElemType e,e0;
    Status i;
    int j,k;
    InitList(L);
    for(j=1;j<=5;j++){
        i=ListInsert(L,1,j);
        if(!i) //插入失败
            exit(ERROR);
    }
    ListInsert(L,6,10);
    printf("在L的表头依次插入1~5后：L=");
    ListTraverse(L,printd);
    i=ListEmpty(L);
    printf("L是否空：i=%d(1:是 0:否)\n",i);
    ClearList(L);
    printf("清空L后：L=");
    ListTraverse(L,printd);
    i=ListEmpty(L);
    printf("L是否空：i=%d(1:是 2：否)\n",i);
    for(j=1;j<=10;j++)
        ListInsert(L,j,j);
    printf("在L的表尾依次插入1~10后：L=");
    ListTraverse(L,printd);
    i=GetElem(L,5,e);
    if(i==OK)
        printf("第5个元素的值为：%d\n",e);
    for(j=0;j<=1;j++){
        k=LocateElem(L,j,equal);
        if(k)
            printf("第%d个元素的值为%d\n",k,j);
        else
            printf("没有元素的值为%d\n",j);
    }
    //测试两头的元素
    for(j=1;j<=2;j++){
        GetElem(L,j,e0); //把第i个元素赋值给
        i=PriorElem(L,e0,e); //求e0的前驱
        if(i==INFEASIBLE)
            printf("元素%d无前驱\n",e0,e);
        else
            printf("元素%d的前驱为：%d\n",e0,e);
    }

    for(j=ListLength(L)-1;j<ListLength(L);j++) //最后两个元素
    {
        GetElem(L,j,e0); //把第i个元素赋值给
        i=PriorElem(L,e0,e); //求e0的前驱
        if(i==INFEASIBLE)
            printf("元素%d无前驱\n",e0,e);
        else
            printf("元素%d的前驱为：%d\n",e0,e);
    }

    k=ListLength(L); //k为表长
    for(j=k+1;j>=k;j--){
        i=ListDelete(L,j,e);
        if(i==ERROR)
            printf("删除第%d个元素失败\n",j);
        else
            printf("删除第%d个元素成功，其值为：%d\n",j,e);
    }
    printf("依次输出L的元素：");
    ListTraverse(L,printd);
    printf("非降序插入元素：");
    InsertAscend(L,20,comp);
    InsertAscend(L,10,comp);
    ListTraverse(L,printd);
    if(Point(L,10,equal,p))
        printf("返回前驱节点：%d\n",p->data);
    DestoryList(L);
    printf("销毁L后，L=%u\n",L);

}