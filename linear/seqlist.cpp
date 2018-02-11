//--------------bo2-1.cpp-----------
//顺序表示的线性表（存储结构由seqlist.h定义）基本操作（12个）

//构造一个空的顺序线性表L
void InitList(SqList &L){
    L.elem=(ElemType*)malloc(LIST_INI_INIT_SIZE*sizeof(ElemType));
    if(!L.elem)
        exit(OVERFLOW); //存储分配失败
    L.length=0; //空表长度为0
    L.listsize=LIST_INI_INIT_SIZE;//初始存储容量

}

//销毁顺序线性表L
void DestoryList(SqList &L){
    free(L.elem);
    L.elem=NULL;
    L.length=0;
    L.listsize=0;
}

//线性表L已存在，将L重置为空表
void ClearList(SqList &L){
    L.length = 0;
}

//顺序线性包L已存在，判断表是否是空表
//为空表返回TRUE，否则返回FALSE
Status ListEmpty(SqList L){
    if(L.length==0){
        return TRUE;
    } else{
        return FALSE;
    }
}

//L存在，返回L中元素个数
int ListLength(SqList L){
    return L.length;
}

//如果顺序线性表L已存在，1<=i<=ListLength(L)
//用e返回L中第i个元素的值
//并用return 返回函数的值是否存在
Status GetElem(SqList L, int i, ElemType &e){
    if(i<1 || i>L.length)
        return ERROR;
    e=*(L.elem+i-1);
    return OK;
}

//初始条件：顺序线性表L已存在，compare()是数据元素判断函数（满足为1，否则为0）
//操作结果：返回L中第1个与e满足compare()的数据元素的位序
//若这样的数据元素不存在，则返回值为0.
int LocateElem(SqList L, ElemType e, Status(*compare)(ElemType,ElemType)){
    ElemType *p;
    int i=1;
    p=L.elem;

    while(i<=L.length && !compare(*p++,e)){
        i=i+1;
    }

    if(i<=L.length)
        return i;
    else
        return 0;
}

//顺序线性表L已存在，1<=i<=ListLength(L)+1
//在L中第i个位置之前插入新的数据元素e，L的长度加1
Status ListInsert(SqList &L,int i,ElemType value){
    ElemType *newbase,*q,*p;

    if(i<1 || i>L.length+1) { //i值不合法
        return ERROR;
    }
    //当前的存储空间已满，增加分配
    if(L.length>=L.listsize){

        newbase=(ElemType*)realloc(L.elem,(L.listsize+LIST_INCREMENT)* sizeof(ElemType));
        if(!newbase)
            exit(OVERFLOW); //分配存储空间失败，退出程序
        L.elem=newbase;  //新基址
        L.listsize+=LIST_INCREMENT; //每次增加两个空间
    }

//    p=L.elem;
//    q=L.elem+L.length;
//    while (q>(p+i)){
//        *q=*(q-1);
//         q=q-1;
//    }
//    *q=value;

    q=L.elem+i-1; //当前插入位置
    for(p=L.elem+L.length;p>q;p--){ //插入位置之后的元素右移
        *p=*(p-1);
    }
    *q=value; //插入元素value
    L.length++; //表长增加1

    return OK;
}

//顺序表L已存在
//若cur_e是L的数据元素，且不是第一个，则用pre_e返回它的前驱值
//否则操作失败，pre_e无定义
Status PriorElem(SqList L, ElemType cur_e, ElemType &pre_e){
    int i=2;
    ElemType *p=L.elem+1;

    //找到cur_e元素
    while (i<=L.length&&*p!=cur_e){
        p++;
        i++;
    }

    if(i>L.length)
        return INFEASIBLE; //操作失败
    else{
        pre_e = *--p;
        return OK;
    }
}

//顺序表L已存在
//若cur_e是L的数据元素，且不是第一个，则用next_e返回它的前驱值
//否则操作失败，next_e无定义
Status NextElem(SqList L, ElemType cur_e, ElemType &next_e){
    int i=1;
    ElemType *p=L.elem;

    //找到cur_e元素
    while(i<L.length-1&&*p!=cur_e){
        p++;
        i++;
    }

    if(i>L.length-1){
        return INFEASIBLE; //未找到该元素
    }else{
        next_e=*++p; //赋值给返回值
        return OK;
    }
}

//顺序线性表L已存在，1<=i<=ListLength(L)
//删除L的第i个元素，并用e返回其值，L的长度减1
Status ListDelete(SqList &L, int i, ElemType &e){
    ElemType *q,*p;
    if(i<1 || i>L.length){ //i值不合法
        return ERROR;
    }

    p=L.elem+i-1; //p为被删除元素的位置
    e=*p; //被删除元素值赋给e

    q=L.elem+L.length-1; //表尾元素的位置
    while(p<q){  //被删除元素之后的元素左移
        *p=*(p+1);
        p++;
    }

    L.length--; //表长减1
    return TRUE;
}

//依次对L的每个元素调用函数vi()
//vi()的形参加'&'，表明可通过调用vi()改变元素的值
void ListTraverse(SqList L, void(*vi)(ElemType&)){
   ElemType *p;
    int i;
    p=L.elem;
    for(i=1;i<L.length;i++){
        vi(*p++);
    }

    printf("\n");
}



void PrintList(SqList &L){
    using namespace std;
    for(int i=0;i<L.length;i++){
        cout<<*(L.elem+i)<<endl;
    }
}