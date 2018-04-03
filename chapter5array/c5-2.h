//c5-2.h 稀疏矩阵的三元组顺序存储表示
#define MAX_SIZE 100 //非零元个数的最大值
//矩阵中的一个元素
struct Triple{
    int i,j; //行下标，列下标
    ElemType e;//非零元素值
};

//TSMatrix为稀疏矩阵
struct TSMatrix{
    //非零元三元组表，data[0]未用--用于存储每个数据元素
    Triple data[MAX_SIZE+1];
    int mu,nu,tu; //矩阵的行数、列数和非零元个数
};
