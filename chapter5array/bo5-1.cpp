// bo5-1.cpp 顺序存储数组（c5-1.h）的基本操作（5个）

/*
变长参数函数的解析，使用到三个宏va_start,va_arg 和va_end，
再看va_list的定义 typedef char* va_list; 只是一个char指针。
由于开始的时候从右至左把参数压栈，va_start 传入最左侧的参数，
往右的参数依次更早被压入栈，因此地址依次递增（栈顶地址最小）。
va_arg传入当前需要获得的参数的类型，便可以利用 sizeof 计算偏移量，
依次获取后面的参数值。
 */

//若维数dim和各维长度合法，构造相应的数组A，并返回OK
//dim表示数组的位数，可变参数表示每一维中数组元素的个数
Status InitArray(Array &A, int dim,...){
    int elemtotal=1,i; //emetotal是数组元素总数，初值为1（累成器）
    va_list ap;
    if(dim<1 || dim>MAX_ARRAY_DIM)
        return ERROR;
    A.dim=dim;
    A.bounds=(int *)malloc(dim* sizeof(int));//根据数组维数分配
    if(!A.bounds)
        exit(OVERFLOW);
    va_start(ap,dim);

    for(i=0;i<dim;i++){
        A.bounds[i]=va_arg(ap,int);//存储每一维数组元素
        if(A.bounds[i]<0)
            return UNDERFLOW;
        elemtotal*=A.bounds[i]; //总共数据元素个数
    }
    va_end(ap);
    A.base=(ElemType*)malloc(elemtotal* sizeof(ElemType));//用于存储所有的元素
    if(!A.base)
        exit(OVERFLOW);

    A.constants=(int *)malloc(dim* sizeof(int)); //存储每一维元素的起始地址
    if(!A.constants)
        exit(OVERFLOW);
    //每移动一行或一列相差的元素个数，由后向前看
    //根据公式:LOC[aj1j2…jn]=LOC[a11 …1]+[(b2*…*bn)*(j1-1)
    //+ (b3*…*bn)*(j2-1)+ …
    //+ bn*(jn-1-1)+(jn-1)]
   A.constants[dim-1]=1;
    for(i=dim-2;i>=0;--i)
        A.constants[i]=A.bounds[i+1]*A.constants[i+1];
    return OK;
}

//销毁数组A
void DestoryArray(Array &A){
    if(A.base)
        free(A.base);
    if(A.bounds)
        free(A.bounds);
    if(A.constants)
        free(A.constants);
    A.base=A.bounds=A.constants=NULL;
    A.dim=0;
}

//若ap指示的各下标值合法，则求出该元素在A中的相对地址off
//value(),Assign()调用此函数
Status Locate(Array A,va_list ap, int &off){
    int i,ind;
    off=0;
    for(i=0;i<A.dim;i++){
        ind=va_arg(ap,int);
        if(ind<0||ind>A.bounds[i])
            return OVERFLOW;
        off+=A.constants[i]*ind;
    }

    return OK;
}

//在vc++中，...之前的形参不能使应用类型
//...依次为各维的下标值，若各下标合法，则e被赋值为A的相应元素（获取元素值）
Status Value(ElemType &e,Array A,...){
    va_list ap;
    va_start(ap,A.dim);
    int off;
    if(Locate(A,ap,off)==OVERFLOW){
        return ERROR;
    }

    e=*(A.base+off);
    return OK;

}

//若各维的下标值合法，则将e的值依次赋给各维的下标值
Status Assign(Array A, ElemType e,...){
    va_list ap;
    va_start(ap,A.dim);
    int off;

    if(Locate(A,ap,off)==OVERFLOW)
        return ERROR;

    *(A.base+off)=e;
    return OK;
}