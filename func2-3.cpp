//func2-3 几个常用函数
Status equal(ElemType e1, ElemType e2){
    if(e1==e2)
        return TRUE;
    else
        return FALSE;
}

void printd(ElemType e){
    printf("%d ",e);
}

void printch(ElemType e){
    printf("%c ",e);
}

int comp(ElemType e1,ElemType e2){
    if(e1==e2)
        return 0;
    else if(e1>e2)
        return 1;
    else
        return -1;
}
