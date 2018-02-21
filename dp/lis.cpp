//最长递增子序列（Longest Increasing Subsequence,lis）
//对于一个序列如1，-1，2，-3，4，-5，6，-7，其最长第增子序列为1,2,4,6。
#include <iostream>
#include "limits.h"

typedef struct{
    int length;
    int pre;
} State;

void lisCompare(int lis[],int n){
    State s[n+1],tmp;
    int i,j;

    //只使用第0行
    for(i=0;i<n;i++){
        s[i].length=1;
    }

    for(i=1;i<n+1;i++){
        tmp.length=1;
        for(j=0;j<i;j++){
            if(lis[i]>lis[j] && tmp.length+1>s[j].length){
                printf("%d,%d\n",lis[i],lis[j]);
                tmp.length=s[j].length+1;
            }
        }
        s[i].length=tmp.length;
        s[i].pre=lis[i];
    }

    for(i=0;i<n;i++)
        printf("s[%d]= %d\n",i+1,s[i].length);

}

int main(){
    //int lis[]={1,-1,2,-3,4,-5,6,-7,9};
    int lis[]={1,-10,2,-7,4,-6,3,5,9};
    lisCompare(lis, sizeof(lis)/sizeof(lis[0]));
}