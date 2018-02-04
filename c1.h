//c1.h引入要使用的头文件-公共头文件
#include <string.h>
#include <ctype.h>
#include <malloc.h> //malloc()等
#include <limits.h>  //INT_MAX等
#include <stdio.h>  //EOF(=^Z或F6),NULL
#include <stdlib.h> //atoi()
#include <io.h> //eof()
#include <math.h> //floor(),ceil(),abs()
#include <process.h> //exit()
#include <iostream> //cout,cin

//函数结果状态代码
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1

//在math.h中已定义OVERFLOW的值为3，故去掉此行
typedef int Status; //Status是函数的类型，其值时函数结果状态代码，如OK
typedef int Boolean; //Boolean是布尔类型，其值时TRUE或FALSE
