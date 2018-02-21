#include <iostream>
#include <cstring>

#define MAXLEN 20
#define MATCH 0
#define INSERT 1
#define DELETE 2

typedef struct{
    int cost; //cost表示字符串相似度
    int parent; //parent表示当前进行的操作
} Cell;


int match(char a,char b){
    //cost of match
    //match:0
    //not match:1
    return (a==b)?0:1;
}

int stringCompare(char *s,char *t){
    Cell m[MAXLEN+1][MAXLEN+1];
    int i,j,k;
    int opt[3];

    //row_init(i)
    //设置每行的第一列的初始值为insert（默认值）
    for(i=0;i<=MAXLEN;i++){
        m[i][0].cost=i;
        if(i==0)
            m[i][0].parent=-1;
        else
            m[i][0].parent=INSERT;
    }

    //column_init(i)
    //设置第一行的初始值
    for(i=0;i<=MAXLEN;i++){
        m[0][i].cost=i;
        if(i==0)
            continue;
        else
            m[0][i].parent=INSERT;
    }

    char m_s[MAXLEN+1]=" ";
    char m_t[MAXLEN+1]=" ";
    strcat(m_s,s); //将s拼接到m_s之后
    strcat(m_t,t);

    //对于i>0,j>0的状态(i,j),m[i][j]=min(m[i-1][j-1]+(s[i]==s[j])?0:1,m[i-1][j]+1,m[i][j-1]+1)
    //这里的重叠子结构是S[1...i]，T[1...j]
    //以下是相应代码。考虑到数组下标从0开始，做了一个转化将字符串后移一位。

    //用s的前i个字符依次与t的所有字符比较，查看将前i个字符变为t样式所花费的代价
    //计算将s的前i个字符变为t的样式所花费的cost
    for(i=1;i<=strlen(s);i++){
        for(j=1;j<=strlen(t);j++){
            //三种情况：1.匹配或者替换；2.插入；3.替换
            //匹配为0，替换、插入、替换次数为1=>求最小次数
            //修改S或T末尾字符使其与另一个一致来完成，m[len(S)][len(T)]=m[len(S)-1][len(T)-1]+1；
            //1.如果匹配，则m[i][j]与m[i-1][j-1]的cost相同
            //2.如果替换，则m[i][j]相对于m[i-1][j-1]cost加1（即i和j的前一个字符）
            opt[MATCH]=m[i-1][j-1].cost+match(m_s[i],m_t[j]);
            //3.如果在t(少的)当前位置插入一个元素，则插入的元素与t位置的j元素匹配，i本身的值不变，用i与s的下一个值比较
            //在S末尾插入T末尾的字符，比较S[1...len(S)]和S[1...len(T)-1]；
            //在T末尾插入S末尾的字符，比较S[1...len(S)-1]和S[1...len(T)]；
            //举例，如果在i的末尾插入字符，则i的位置不变，下一次比较i和j-1的位置
            //相当于i+1与j已经匹配，下一步要查看i与j-1匹配所花费的cost（这就是由后之前）
            opt[INSERT]=m[i][j-1].cost+1;
            //4.如果在s当前j位置删除一个元素，则i的位置不变，相对于j-1位置的cost加1；
            //opt[DELETE]=m[i][j-1].cost+1;
            opt[DELETE]=m[i-1][j].cost+1;

            m[i][j].cost=opt[MATCH];
            m[i][j].parent=MATCH;

            for(k=INSERT;k<=DELETE;k++){
                if(m[i][j].cost>opt[k]){
                    m[i][j].cost=opt[k];
                    m[i][j].parent=k;
                }
            }
        }
    }
    --i;
    --j;
    printf("m[%d][%d]:%d\n",i,j,m[i][j].cost);
}

int main(){
    //char t[]="you should not";
    //char p[]="thou shalt not";
    char t[]="yo";
    char p[]="tho";


    int n=stringCompare(t,p);
    printf("%d\n",n);
}
