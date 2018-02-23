// c3-2.h 单链队列--队列的链式存储结构
//这是队列中的每一个节点
typedef struct QNode{
    ElemType data;
    QNode *next;
} *QueuePtr;

//这是队列本身
struct LinkQueue{
    QueuePtr front,rear; //队头、队尾指针
};
