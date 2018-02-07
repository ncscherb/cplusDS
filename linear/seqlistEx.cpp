//顺序表扩展文件
//将所有在线性表Lb中但不在La中的数据元素插入到La中
void Union(SqList &La, SqList Lb){
    ElemType e;
    int La_len,Lb_len;
    int i;
    La_len=ListLength(La);
    Lb_len=ListLength(Lb);

    for(i=1;i<=Lb_len;i++){
        GetElem(Lb,i,e);
        if(LocateElem(La,e,equal)==0){
            ListInsert(La,La.length+1,e);
        }
    }
}

//已知线性表La和Lb中的元素按值非递减排列
//归并La和Lb得到新的线性表Lc，Lc的数据元素也按值非递减排列
void MergeList(SqList La,SqList Lb, SqList &Lc){
    int i=1,j=1;
    int v1,v2;

    while (i<=La.length&&j<=Lb.length){
        GetElem(La,i,v1);
        GetElem(Lb,j,v2);

        if(v1<v2){
            ListInsert(Lc,Lc.length+1,v1);
            i++;
        } else if(v1>v2){
            ListInsert(Lc,Lc.length+1,v2);
            j++;
        }else{
            ListInsert(Lc,Lc.length+1,v2);
            j++;
            i++;
        }
    }

    if(i>La.length){
        for(int k=j;k<=Lb.length;k++){
            GetElem(Lb,k,v2);
            ListInsert(Lc,Lc.length+1,v2);
        }
    }
    if(j>La.length) {
        for (int k = i; i <= La.length; k++) {
            GetElem(La,k,v1);
            ListInsert(Lc, Lc.length + 1, v1);
        }
    }

}
