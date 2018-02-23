//矩阵链乘法
#include <iostream>
#include <string>
#include "limits.h"
#define MATRIXLEN 6
using namespace std;

typedef struct {
    int row;
    int col;
} Matrix;

void printChain(int **s, int i, int j);
//自底向上法
void matrixChainOrder(Matrix ma[], int n){
   int i,j,k,temp;
    int **m=(int **)malloc(sizeof(int *)*n);
    for(i=0;i<n;i++){
        m[i]=(int *)malloc(sizeof(int)*n);
        m[i][i]=0;
    }

    int **s=(int **)malloc(sizeof(int *)*n);
    for(i=0;i<n;i++){
        s[i]=(int *)malloc(sizeof(int)*n);
        s[i][i]=0;
    }

    //第一层循环的含义：通过第一层循环，依次产生每两个矩阵并求其最小值
    //然后是每三个，每四个...->这样做，在求四个时，所有要用到的三个都已经算出来了
    for(int l=2;l<=n;l++){
        for(int i=0;i<n-l+1;i++){
            j=i+l-1;
            m[i][j]=INT_MAX;
            for(k=i;k<j;k++){
                temp=m[i][k]+m[k+1][j]+ma[i].row*ma[k].col*ma[j].col;
                if(m[i][j]>temp){
                    m[i][j]=temp;
                    s[i][j]=k+1;
                }
            }
            printf("m[%d][%d]=%d\n",i+1,j+1,m[i][j]);
            //printf("s[%d][%d]=%d\n",i+1,j+1,s[i][j]);
        }
    }

    //打印出所有分隔
    printChain(s,0,n-1);
}

int mr[MATRIXLEN][MATRIXLEN];
int sr[MATRIXLEN][MATRIXLEN];
void matrixChainInit(){
    for(int i=0;i<MATRIXLEN;i++){
        for(int j=0;j<MATRIXLEN;j++){
             mr[i][j]=INT_MAX;
        }
    }
}

int matrixChainRe(Matrix ma[], int i, int j){
    if(i==j){
        mr[i][j]=0;
    }
    for(int k=i;k<j;k++){
       //int temp=matrixChainRe(ma,i,k)+matrixChainRe(ma,k+1,j)+ma[i].row*ma[k].col*ma[j].col;
        int t1=matrixChainRe(ma,i,k);
        int t2=matrixChainRe(ma,k+1,j);
        int t3=ma[i].row*ma[k].col*ma[j].col;
        int temp=t1+t2+t3;
        if(mr[i][j]>temp){
           mr[i][j]=temp;
            sr[i][j]=k+1;
            printf("mr[%d][%d]=%d\n",i+1,j+1,mr[i][j]);
            //printf("sr[%d][%d]=%d\n",i+1,j+1,sr[i][j]);
        }
    }

    return mr[i][j];
}


void printChain(int **s,int i,int j){
    int m=s[i][j];
    if(i==j)
        printf("A%d",i);
    else{
        printf("(");
        printChain(s,i,m-1);
        printChain(s,m,j);
        printf(")");
    }
}

int main(){
    Matrix ma[MATRIXLEN];
    ma[0].row=30;
    ma[0].col=35;
    ma[1].row=35;
    ma[1].col=15;
    ma[2].row=15;
    ma[2].col=5;
    ma[3].row=5;
    ma[3].col=10;
    ma[4].row=10;
    ma[4].col=20;
    ma[5].row=20;
    ma[5].col=25;

    matrixChainOrder(ma, sizeof(ma)/sizeof(ma[0]));
    cout<<"\n";
    matrixChainInit();
    int value=matrixChainRe(ma,0,sizeof(ma)/sizeof(ma[0])-1);
    cout<<"\nre="<<value<<endl;
}

