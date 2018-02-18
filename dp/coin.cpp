#include <iostream>
#include "limits.h"
using namespace std;

typedef struct {
    int nCoin; //使用硬币的数量
    int lastSum; //上一个状态
    int addCoin; //从上一个状态到达当前状态所使用的硬币种类
} State;

void FindMinCoin(int money, int coinType[], int coinTypeLen){
   State *sum=(State *)malloc(sizeof(State)*(money+1));

    for(int i=1;i<=money;i++){
        sum[i].nCoin=INT_MAX;
    }
    sum[1].lastSum=0;
    sum[1].addCoin=0;
    sum[0].nCoin=0;

    //动态规划的方程式F(i)=min(F(i-coinType(j))+1),i-coinType(j)>0
    //i-coinType(j)的含义为：表示当前的money=i,使用了一个面值为coinType(j)的硬币，求i-coinType(j)使用硬币的最小值
    //原理：动态规划思想->如果要找到满足整体的最小值，则从前到后依次找到局部最优解
    //因此先找到money=1时硬币个数的最小值，再找money=2时硬币个数的最小值
    //据此类推，在查找后面硬币个数最小值时，利用前面已经找到的硬币个数最小值。
    for(int i=1;i<=money;i++)
        for(int j=0;j<coinTypeLen;j++){
            //查到money=i时硬币个数最小的两个条件
            //一是当前的money>=硬币的面值，
            // 二是当前使用的硬币数>=上一个状态的硬币数（用上一个状态的硬币数替换当前的硬币数）
            if(i>=coinType[j] && sum[i].nCoin>sum[i-coinType[j]].nCoin+1){
                sum[i].nCoin=sum[i-coinType[j]].nCoin+1;
                sum[i].addCoin=coinType[j];
                sum[i].lastSum=sum[i-coinType[j]].lastSum+sum[i-coinType[j]].addCoin;
            }

        }

    if(sum[money].nCoin==INT_MAX)
        printf("can't make change.\n");
    else{
        cout<<"nCoin:"<<sum[money].nCoin<<endl;
        cout<<"lastSum:"<<sum[money].lastSum<<endl;
        cout<<"addCoin:"<<sum[money].addCoin<<endl;
    }
}

int main(){
    int money=18;
    int coin[]={1,2,5,9,10};

    FindMinCoin(money,coin,5);

}