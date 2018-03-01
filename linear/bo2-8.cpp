//bo2-8.cpp不带头结点的单链表（存储结构由c2-2.h定义）基本操作11个
//L为不带头结点的单链表的头指针
#define DestoryList ClearList ;
//构造一个空的线性表L
void InitList(LinkList &L){
    L=NULL;
}

//将L重置为空表
void ClearList(LinkList &L){
    LinkList p;
    while (L){ //L不为空
        p=L; //p指向首元结点
        L=L->next;
        free(p);
    }
}

//判断线性表是否为空
Status ListEmpty(LinkList L){
    if(L)
        return FALSE;
    else
        return TRUE;
}

//返回线性表元素个数
int ListLength(LinkList L){
   LinkList p;
    p=L;
    int i=0;
    while (p){
        i++;
        p=p->next;
    }

    return i;
}

//L为不带头结点的单链表的头指针,当第i个元素存在时，其值赋给e并返回OK
Status GetElem(LinkList L,int i,ElemType &e){
    int j=1;
    LinkList p=L;

    if(i<1)
        return ERROR;

    while (j<i&&p){
        p=p->next;
        j++;
    }

    //如果存在第i个元素
    if(j==i){
        e=p->data;
        return OK;
    } else
        return ERROR;
}

//返回L中第1个与e满足关系compare()元素的位序。若这样的数据元素不存在，则返回值为0
int LocateElem(LinkList L,ElemType e,Status(*compare)(ElemType,ElemType)){
    int i=1;
    LinkList p=L;
    while (p){
        if(compare(p->data,e))
            return i;
        p=p->next;
        i++;
    }

    return 0;
}

//在不带头结点的单链线性表L中第i个位置之前插入元素e
Status ListInsert(LinkList &L,int i,ElemType e){
    int j=1;
    LinkList p=L,q;
    if(i<1)
        return ERROR;

    q=(LinkList)malloc(sizeof(LNode));//生成新结点
    q->data=e;
    if(i==1){
        q->next=L;
        L=q;
    }else{
        //找到第i个元素之前的一个
        while (j<i-1&&p){
            j++;
            p=p->next;
        }

        if(!p) //i大于表长+1
            return ERROR;
        q->next=p->next;
        p->next=q;
    }
    return OK;
}

//删除第i个元素，并由e返回其值
Status ListDelete(LinkList &L,int i,ElemType &e){
    int j=1;
    LinkList p=L,q;
    if(i==1){//删除第1个节点
        L=L->next; //L由第2个节点开始
        e=p->data;
        free(p); //删除并释放第1个节点
    } else{
        //寻找第i-1个节点，由其删除第i个节点
        while(j<i-1&&p){
            j++;
            p=p->next;
        }
        if(!p->next||j>i-1) //删除位置不合理
            return ERROR;
        q=p->next; //删除并释放节点
        p->next=q->next;
        e=q->data;
        free(q);

    }
}

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

//依次对L的每个元素调用vi()函数
void ListTraverse(LinkList L,void(*vi)(ElemType)){
    LinkList p=L;
    while (p){
        vi(p->data);
        p=p->next;
    }
    printf("\n");
}
