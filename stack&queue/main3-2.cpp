//main3-2.cpp 检验bo3-2.cpp的主程序
#include "../c1.h"
typedef int QElemType;
#include "c3-2.h"
#include "bo3-2.cpp"

void print(ElemType i){
    printf("%d ",i);
}

int main(){
    int i;
    ElemType d;
    LinkQueue q;
    InitQueue(q);
    printf("成功地构造了一个空队列！\n");
    printf("是否空队列？%d(1:空 0：否) ",QueueEmpty(q));
    printf("队列的长度为%d\n",QueueLength(q));
    EnQueue(q,-5);
    EnQueue(q,5);
    EnQueue(q,10);
    printf("插入3个元素（-5,5,10）后，队列长度为%d\n",QueueLength(q));
    printf("是否空队列？%d(1:空 0：否 ",QueueEmpty(q));
    printf("队列的元素依次为： ");
    QueueTraverse(q,print);
    i=GetHead(q,d);
    if(i==OK)
        printf("队头元素时：%d\n",d);
    DeQueue(q,d);
    printf("删除了队头元素%d\n",d);
    i=GetHead(q,d);
    if(i==OK)
        printf("新的队头元素是：%d\n",d);
    ClearQueue(q);
    printf("清空队列后，q.front=%u q.rear=%u q.front->next=%u\n",
    q.front,q.rear,q.front->next);
    DestoryQueue(q);
    printf("销毁队列后，q.front=%u q.rear=%u", q.front,q.rear);
}

