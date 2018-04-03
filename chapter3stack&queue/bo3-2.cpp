//bo3-2.cpp链队列（存储结构由c3-2.h定义）的基本操作（9个）
//构造一个空队列Q
void InitQueue(LinkQueue &Q){
    if(!(Q.front=Q.rear=(QueuePtr)malloc(sizeof(QNode))))
        exit(OVERFLOW);
    Q.front->next=NULL; //队尾指针的下一个元素为空
}

//销毁队列Q(无论空否均可)
void DestoryQueue(LinkQueue &Q){
    while (Q.front){
        Q.rear=Q.front->next;
        free(Q.front);
        Q.front=Q.rear;
    }
}

//将Q轻为空队列
void ClearQueue(LinkQueue &Q){
    QueuePtr p,q;
    Q.rear=Q.front;
    p=Q.front->next;
    Q.front->next=NULL;
    while(p){
        q=p;
        p=p->next;
        free(q);
    }
}

//若Q为空队列，则返回True,否则返回FALSE
Status QueueEmpty(LinkQueue Q){
    if(Q.front->next==NULL)
        return TRUE;
    else
        return FALSE;
}

//对队列长度
int QueueLength(LinkQueue Q){
    int i=0;
    QueuePtr p;
    p=Q.front->next;
    while (p){
        i++;
        p=p->next;
    }

    return i;
}


//用e返回Q的队头元素，并返回OK;
Status GetHead(LinkQueue Q,QElemType &e){
    QueuePtr p;
    if(Q.front==Q.rear){ //判断队列是否为空
        return ERROR;
    }

    p=Q.front->next;
    e=p->data;
    return OK;
}

//插入元素e为Q的新队尾元素
void EnQueue(LinkQueue &Q,QElemType e){
    QueuePtr p;
    if(!(p=(QueuePtr)malloc(sizeof(QNode))))//存储空间分配失败
        exit(OVERFLOW);
    p->data=e;
    p->next=NULL;
    Q.rear->next=p;
    Q.rear=p;
}

//删除Q的队头元素，用e返回其值，并返回OK
Status DeQueue(LinkQueue &Q, QElemType &e){
    QueuePtr p;
    if(Q.rear==Q.front)
        return ERROR;
    p=Q.front->next;
    e=p->data;
    Q.front->next=p->next;
    if(Q.rear==p)
        Q.rear=Q.front;
    free(p);
    return OK;
}

//从队头到队尾依次对队列Q中每个元素调用函数vi()
void QueueTraverse(LinkQueue Q,void(*vi)(QElemType)){
    QueuePtr p;
    p=Q.front->next;

    while(p){
        vi(p->data);
        p=p->next;
    }
    printf("\n");
}
