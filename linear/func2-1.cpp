//func2-1.cpp 不带头结点的单链（存储结构由c2-2.h定义）的扩展操作(3个)
//algo2-6.cpp和bo7-2.cpp用到
//#include "c2-2.h"
#include "bo2-8.cpp"

#include "c2-2.h"

//按关键字非降序将e插入表L.函数compare返回值为：形参1的关键字，形参2的关键字
void InsertAscend(LinkList &L,ElemType e,int(*compare)(ElemType,ElemType)){
    LinkList p=L;
    int i=1;
    //链表空或e的关键字小于等于首节点的关键字
    if(!L || compare(e,p->data)<0)
        ListInsert(L,1,e);
    else{
//        while(p&&compare(e,p->data)>0){
//            p=p->next;
//            i++;
//        }
//        ListInsert(L,i,e);
        //用p->next是考虑到最后一个为空
        while (p->next&&compare(e,p->next->data)>0){
            p=p->next;
        }
        ListInsert(p,2,e);
    }

}

//查找表L中满足条件的节点。如果找到，返回指向该节点的指正，p指向该节点的前驱
//若该节点是首元节点，则p=NULL，如果L中无满足条件的节点，则返回NULL,p
//无定义。函数equal()的两形参的关键字相等，返回OK；否则返回ERROR
//Point返回的是与e相等的节点，p是该节点的前驱
LinkList Point(LinkList L,ElemType e, Status(*equal)(ElemType,ElemType),LinkList &p){
    LinkList q=L;

    p=NULL;
    if(!q)
        return NULL;
    if(q->data==e)
        return q;

    while (q->next){
        if(equal(q->next->data,e)){
            p=q;
            return q->next;
        }
        q=q->next;
    }

    return NULL;
}

LinkList Point1(LinkList L,ElemType e, Status(*equal)(ElemType,ElemType),LinkList &p){
    int i,j;
    i=LocateElem(L,e,equal);
    if(i){//找到
        if(i==1){
            p=NULL;
            return L;
        }
        p=L;
        for(j=2;j<i;j++)
            p=p->next;
        return p->next;
    }
    return NULL; //没有找到
}

//删除表L中满足条件的节点，并返回TRUE；如果无此节点，返回FALSE
Status DeleteElem(LinkList &L,ElemType &e,Status(*equal)(ElemType,ElemType)){
    LinkList p,q;
    q=Point1(L,e,equal,p);
    if(q){//找到该节点
        if(!p){//如果是首节点
            ListDelete(L,1,e);
        } else{
            ListDelete(p,2,e);//将p作为首节点，删除第二个指针
        }
        return TRUE;
    }

    return FALSE;
}