//bo2-9.cpp 不带头结点的单链表（存储结构由c2-2.h定义）的部分基本操作（2个）

//若cur_e是L的数据元素，且不是第一个，则用pre_e返回它的前驱，返回OK;
//否则操作失败，pre_e无定义，返回INFEASIBLE
Status PriorElem(LinkList L,ElemType cur_e,ElemType &pre_e){
    LinkList p=L;

    if(!p)
        return INFEASIBLE;

    while(p->next){
        if(p->next->data==cur_e){
            pre_e=p->data;
            return OK;
        }
        p=p->next;
    }

    return INFEASIBLE;

}

//若cur_e是L的数据元素，且不是最后一个，则用next_e返回它的后继，返回OK;
//否则操作失败，next_e无定义，返回INFEASIBLE
Status NextElem(LinkList L,ElemType cur_e,ElemType &next_e){
    LinkList p=L,q;

    while(p){
        if(p->data==cur_e && p->next!=NULL){
            next_e=p->next->data;
            return OK;
        }
        p=p->next;
    }

    return INFEASIBLE;
}

