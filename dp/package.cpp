#include <iostream>

//n是物品总数，total是能带走的总重量
void package_dp(int *v,int *w,int n,int total){
    int i,j,tmp1,tmp2;

    //构造一个(n+1)*(total+1)的二维数组，数组的行表示物品总数，列表示总重量
    int **c =(int **)malloc(sizeof(int *)*(n+1));
    for(i=0;i<n+1;i++)
        c[i]=(int *)malloc(sizeof(int)*(total+1));

    //将第0行的所有列值置为0（额外行，作为初始值）
    for(i=0,j=0;j<total+1;j++)
        c[i][j]=0;

    for(i=1;i<n+1;i++){
        c[i][0]=0; //每一行的第一列置为0，额外列，作为初始值
        for(j=1;j<total+1;j++){
           if(j<w[i]){ //如果当前的重量j小于物品的重量，则该物品不能加入背包中,保持之前背包的物品
               c[i][j]=c[i-1][j];

           } else{
               //如果加上当前的物品之后的价值大于上一次的价值，则使用该物品
               //if(c[i-1][j]<c[i][j-w[i]]+v[i])
               //     c[i][j]=c[i][j-w[i]]+v[i];
               tmp1=c[i-1][j];
               tmp2=c[i][j-w[i]]+v[i];

               c[i][j]=tmp1>tmp2?tmp1:tmp2;
           }
        }
    }
    printf("c[%d][%d]:%d\n",n,total,c[n][total]);
}

int main(){
    int value[]={0,10,25,40,20,10};
    int w[]={0,40,50,70,40,20};
    int total=120;

    package_dp(value,w,5,total);
}

