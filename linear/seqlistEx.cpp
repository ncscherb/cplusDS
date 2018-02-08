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
            ListInsert(La,La_len+1,e);
        }
    }
}

//已知线性表La和Lb中的元素按值非递减排列
//归并La和Lb得到新的线性表Lc=>不去除重复元素，Lc的数据元素也按值非递减排列
void MergeList(SqList La,SqList Lb, SqList &Lc){
    int i=1,j=1;
    int La_len=ListLength(La);
    int Lb_len=ListLength(Lb);
    ElemType v1,v2; //使用变量类型定义变量

    while (i<=La_len&&j<=Lb_len){
        GetElem(La,i,v1);
        GetElem(Lb,j,v2);

        if(v1<=v2){
            ListInsert(Lc,Lc.length+1,v1);
            i++;
        } else{
            ListInsert(Lc,Lc.length+1,v2);
            j++;
        }
    }


    //以下两种方法任选一个
    //方法一
    while(i<=La_len){
        GetElem(La,i++,v1);
        ListInsert(Lc,Lc.length+1,v1);
    }

    while(j<=Lb_len){
        GetElem(Lb,j++,v2);
        ListInsert(Lc,Lc.length+1,v2);
    }

    //方法二
    /*
    if(i>La_len){
        for(int k=j;k<=Lb_len;k++){
            GetElem(Lb,k,v2);
            ListInsert(Lc,Lc.length+1,v2);
        }
    }
    if(j>La_len) {
        for (int k = i; i <= La_len; k++) {
            GetElem(La,k,v1);
            ListInsert(Lc, Lc.length + 1, v1);
        }
    }
     */

}
