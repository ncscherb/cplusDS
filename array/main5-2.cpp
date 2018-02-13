//main5-2.cpp 检验bo5-2.cpp 的主程序
#include "../c1.h"
typedef int ElemType;
#include "c5-2.h"
#include "bo5-2.cpp"

int main(){
    TSMatrix A,B,C,D,E;
    printf("创建矩阵A:");
    CreateSMatrix(A);
//    PrintSMatrix(A);
//    printf("由矩阵A复制矩阵B:\n");
//    CopySMatrix(A,B);
//    PrintSMatrix1(B);
//    DestorySMatrix(B);
//    printf("销毁矩阵B后：\n");
//    PrintSMatrix1(B);
//    printf("创建矩阵B2:(与矩阵A的行、列相同，行列分别为%d，%d)\n",A.mu,A.nu);
//    CreateSMatrix(B);
//    PrintSMatrix1(B);
//    AddSMatrix(A,B,C);
//    printf("矩阵C1(A1+B1):\n");
//    PrintSMatrix1(C);
//    SubSMatrix(A,B,C);
//    printf("矩阵C2(A2-B2):\n");
//    PrintSMatrix1(C);
//    printf("矩阵C3(A的转置):\n");
//    TransposeSMatrix(A,D);
//    PrintSMatrix1(D);
//    PrintSMatrix(D);

    printf("创建矩阵E:");
    CreateSMatrix(E);

    printf("矩阵乘积1：\n");
    MultSMatrix(A,E,B);
    PrintSMatrix1(B);

    printf("矩阵乘积2：\n");
    MultSMatrix(A,E,C);
    PrintSMatrix1(C);

    printf("矩阵乘积3：\n");
    MultSMatrix(A,E,C);
    PrintSMatrix1(C);
}

