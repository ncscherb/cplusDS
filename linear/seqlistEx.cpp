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

//-----------algo2-2(使用的是索引)--------------
//已知线性表La和Lb中的元素按值非递减排列
//归并La和Lb得到新的线性表Lc=>不去除重复元素，Lc的数据元素也按值非递减排列
void MergeList(SqList La,SqList Lb, SqList &Lc){
    int i=1,j=1;
    int La_len=ListLength(La);
    int Lb_len=ListLength(Lb);
    ElemType v1,v2; //使用变量类型定义变量
    InitList(Lc);

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

//-----------algo2-3(使用指针)--------------
//已知线性表La和Lb中的元素按值非递减排列
//归并La和Lb得到新的线性表Lc=>不去除重复元素，Lc的数据元素也按值非递减排列
void MergeList2(SqList La, SqList Lb, SqList &Lc){
    ElemType  *pa,*pa_last,*pb,*pb_last,*pc;
    pa=La.elem;
    pb=Lb.elem;

    Lc.listsize=Lc.length=La.length+Lb.length;
    pc=Lc.elem=(ElemType*)malloc(Lc.length*sizeof(ElemType));
    if(!Lc.elem){
        exit(OVERFLOW);
    }

    pa_last=pa+La.length-1;
    pb_last=pb+Lb.length-1;

    //表La和表Lb均非空
    while (pa<=pa_last&&pb<=pb_last){
        //归并
        if(*pa<=*pb){
            //将pa所指单元的值赋值给pc所指单元后，pa和pc分别＋1，指向下一个单元
            *pc++=*pa++;
        }else{
            *pc++=*pa++;
        }
    }

    //以下两个中只有一个执行
    while(pa<=pa_last)
        *pc++=*pa++;
    while(pb<=pb_last)
        *pc++=*pb++;
}

//--------algo2-4(使用的是指针-compare)---------
//另一种合并线性表的方法，La、Lb、Lc都是按递增排列的表
//第一个循环语句中的条件语句为开关语句，且当*pa=*pb时，
//只将两者之一插入Lc。
void MergeList3(SqList La,SqList Lb,SqList &Lc){
    ElemType *pa,*pa_last,*pb,*pb_last,*pc;
    pa=La.elem;
    pb=Lb.elem;
    Lc.listsize=La.length+Lb.length; //此句与上一句不同
    pc=Lc.elem=(ElemType*)malloc(Lc.listsize*sizeof(ElemType));

    if(!Lc.elem)
        exit(OVERFLOW);
    pa_last=La.elem+La.length-1;
    pb_last=Lb.elem+Lb.length-1;

    while(pa<=pa_last&&pb<=pb_last){
        switch (comp(*pa,*pb)){
            case 0:pb++;
            case -1:*pc++=*pa++;
                break;
            case 1:*pc++=*pb++;
        }
    }

    while (pa<=pa_last)
        *pc++=*pa++;
    while (pb<=pb_last)
        *pc++=*pb++;
    Lc.length=pc-Lc.elem;
}