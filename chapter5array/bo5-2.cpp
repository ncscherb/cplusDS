//bo5-2.cpp 三元稀疏矩阵的基本操作（8个），包括算法5.1--14video
//#include "c5-2.h"

//创建稀疏矩阵M
Status CreateSMatrix(TSMatrix &M){
    int i,m,n;
    ElemType e;
    Status k;
    printf("请输入矩阵的行数，列数，非零元素个数");
    scanf("%d,%d,%d",&M.mu,&M.nu,&M.tu);
    if(M.tu>MAX_SIZE)
        return ERROR;
    M.data[0].i=0; //为以下比较顺序做准备--第一个元素未用
    for(i=1;i<=M.tu;i++){
        //一直输入直到输入正确为止
        do{
            printf("请按行序顺序输入第%d个非零元素所在的行(1~%d),列（1~%d）,元素值：",i,M.mu,M.nu);
            scanf("%d,%d,%d",&m,&n,&e);
            k=0;
            if(m<1 || m>M.mu||n<1||n>M.nu)//行或列超出范围
                k=1;
            if(m<M.data[i-1].i||m==M.data[i-1].i&&n<=M.data[i-1].j) //行或列的顺序有错
                k=1;
        }while (k);
        M.data[i].i=m;
        M.data[i].j=n;
        M.data[i].e=e;
    }
    return OK;
}

//销毁稀疏矩阵
void DestorySMatrix(TSMatrix &M){
    M.mu=M.nu=M.tu=0;
}

//输出稀疏矩阵
void PrintSMatrix(TSMatrix M){
    int i;
    printf("%d行%d列%d个稀疏矩阵元素\n",M.mu,M.nu,M.tu);
    printf("行   列   元素值\n");

    for(i=1;i<=M.tu;i++)
        printf("%-4d%-4d%-8d\n",M.data[i].i,M.data[i].j,M.data[i].e);
}

//按矩阵形式输出M
void PrintSMatrix1(TSMatrix M){
    int i,j,k=1;

    for(i=1;i<=M.mu;i++){
        for(j=1;j<=M.nu;j++){
            if(i==M.data[k].i&&j==M.data[k].j){
                printf("%-4d",M.data[k].e);
                if(k<=M.tu)
                    k++;
            }else{
                printf("%-4d",0);
            }
        }
        printf("\n");
    }
}

//有稀疏矩阵M复制得到T
void CopySMatrix(TSMatrix M,TSMatrix &T){
    T=M;
}

int comp(int c1,int c2){
    if(c1<c2)
        return -1;
    if(c1==c2)
        return 0;
    return 1;
}

//矩阵相加
Status AddSMatrix(TSMatrix M,TSMatrix N, TSMatrix &Q){
    if(M.nu!=N.nu||N.mu!=M.mu)
        return ERROR;

    Q.mu=M.mu;
    Q.nu=M.nu;

    int i=1,j=1,k=1;
    while(i<=M.tu&&j<=N.tu){
        switch (comp(M.data[i].i,N.data[j].i)){
            case -1:
                Q.data[k++]=M.data[i++];
                break;
            case 1:
                Q.data[k++]=N.data[j++];
                break;
            case 0:
                switch (comp(M.data[i].j,N.data[i].j)){
                    case -1:
                        Q.data[k++]=M.data[i++];
                        break;
                    case 1:
                        Q.data[k++]=N.data[j++];
                        break;
                    case 0:
                        Q.data[k]=M.data[i++];
                        Q.data[k].e+=N.data[j++].e;
                        if(Q.data[k].e==0)
                            k--;
                        k++;
                        break;
                }
        }
    }

    while(i<=M.tu){
        Q.data[k++]=M.data[i++];
    }

    while(j<=N.tu){
        Q.data[k++]=N.data[j++];
    }

    if(k-1>MAX_SIZE)
        return ERROR;

    Q.tu=k-1;
    return OK;
}

//求稀疏矩阵的差M-N
Status SubSMatrix(TSMatrix M,TSMatrix N,TSMatrix &Q){
    int i=1;
    for(i=1;i<=N.tu;i++){
        N.data[i].e*=-1;
    }

    return AddSMatrix(M,N,Q);
}

//求稀疏矩阵的转置矩阵T
void TransposeSMatrix(TSMatrix M,TSMatrix &T){
    int p,q=1,col;
    T.tu=M.tu;
    T.nu=M.mu;
    T.mu=M.nu;

    if(T.tu){
        for(col=1;col<=M.nu;col++)
           for(p=1;p<=T.tu;p++)
               if(col==M.data[p].j){
                   T.data[q].e=M.data[p].e;
                   T.data[q].i=M.data[p].j;
                   T.data[q].j=M.data[p].i;
                   q++;
               }
    }
}

//求稀疏矩阵的乘积Q=MXN
Status MultSMatrix(TSMatrix M,TSMatrix N,TSMatrix &Q){
    int i=1,j=1,row,p,q=1;
    int temp[N.nu+1];//保存乘积之后每一行的值
    int mrow[M.nu+1];

    if(M.nu!=N.mu)
        return ERROR;

    //矩阵的乘法：M矩阵i行的所有列*N矩阵j列的所有行之和 => ij位置的值
    for(row=1;row<=M.mu;row++){
       memset(temp,0,(N.nu+1)*sizeof(int));
       memset(mrow,0,(M.mu+1)*sizeof(int));
        //提取M第一行元素，用M第一行乘积N的所有列，得到Q的第一行
        for(i=1;i<=M.tu;i++){
            if(M.data[i].i==row)
                mrow[M.data[i].j]=M.data[i].e;
        }
        //M矩阵第row行的第j个元素=>查找N矩阵对应列的第j个元素
        for(j=1;j<=N.tu;j++){
            temp[N.data[j].j]+=N.data[j].e*mrow[N.data[j].i];
        }
        for(int k=0;k<=N.nu;k++){
            if(temp[k]!=0){
                Q.data[q].e=temp[k];
                Q.data[q].i=row;
                Q.data[q].j=k;
                q++;
            }
        }
    }
    Q.mu=M.mu;
    Q.nu=N.nu;
    Q.tu=q-1;

    if(Q.tu>MAX_SIZE)
        return ERROR;
    return OK;
}

Status MultSMatrix1(TSMatrix M,TSMatrix N, TSMatrix &Q){
    int i,j;
    ElemType *Nc,*Tc;
    TSMatrix T;//临时矩阵
    if(M.nu!=N.mu)
        return ERROR;
    T.nu=M.mu;//临时矩阵T是Q的转置矩阵
    T.mu=N.nu;
    T.tu=0;

    Nc=(ElemType*)malloc((N.mu+1)* sizeof(ElemType));
    Tc=(ElemType*)malloc((M.mu+1)* sizeof(ElemType));
    if(!Nc || !Tc) //创建临时数组失败
        exit(ERROR);

    for(i=1;i<=N.nu;i++){ //对N的每一列
        for(j=1;j<=N.mu;j++)
           Nc[j]=0;  //矩阵Nc的初值为0
        for(j=1;j<=M.mu;j++)
            Tc[j]=0; //临时数组Tc的初始值为0，[0]不用
        for(j=1;j<=N.tu;j++) //对于N的每一个非零元素
            if(N.data[j].j==i) //属于第i列
                //根据其所在行，将N矩阵第j列的所有元素赋值给Nc
                Nc[N.data[j].i]=N.data[j].e;
        //分别用M矩阵的每一行元素去乘以N矩阵的i列元素=>得到T矩阵的第i列元素
        for(j=1;j<=M.tu;j++){
            Tc[M.data[j].i]+=M.data[j].e*Nc[M.data[j].j];
        }
        for(j=1;j<=M.tu;j++)
            if(Tc[j]!=0){
                T.data[++T.tu].e=Tc[j];
                T.data[T.tu].i=i;
                T.data[T.tu].j=j;
            }
    }

    if(T.tu>MAX_SIZE)
        return ERROR;
    TransposeSMatrix(T,Q);
    DestorySMatrix(T);
    free(Tc);
    free(Nc);

    return OK;
}

Status MultSMatrix2(TSMatrix M,TSMatrix N, TSMatrix &Q){
    int i,j;
    ElemType *Nc,*Tc;
    if(M.nu!=N.mu)
        return ERROR;
    Q.mu=M.mu;
    Q.nu=N.nu;
    Q.tu=0;

    Nc=(ElemType*)malloc((N.mu+1)* sizeof(ElemType));
    Tc=(ElemType*)malloc((M.mu+1)* sizeof(ElemType));
    if(!Nc || !Tc) //创建临时数组失败
        exit(ERROR);

    for(i=1;i<=N.nu;i++){ //对N的每一列
        for(j=1;j<=N.mu;j++)
            Nc[j]=0;  //矩阵Nc的初值为0
        for(j=1;j<=M.mu;j++)
            Tc[j]=0; //临时数组Tc的初始值为0，[0]不用
        for(j=1;j<=N.tu;j++) //对于N的每一个非零元素
            if(N.data[j].j==i) //属于第i列
                //根据其所在行，将N矩阵第j列的所有元素赋值给Nc
                Nc[N.data[j].i]=N.data[j].e;
        //分别用M矩阵的每一行元素去乘以N矩阵的i列元素=>得到T矩阵的第i列元素
        for(j=1;j<=M.tu;j++){
            Tc[M.data[j].i]+=M.data[j].e*Nc[M.data[j].j];
        }
        for(j=1;j<=M.tu;j++)
            if(Tc[j]!=0){
                Q.data[++Q.tu].e=Tc[j];
                Q.data[Q.tu].i=j;
                Q.data[Q.tu].j=i;
            }
    }

    if(Q.tu>MAX_SIZE)
        return ERROR;
    free(Tc);
    free(Nc);

    return OK;
}
