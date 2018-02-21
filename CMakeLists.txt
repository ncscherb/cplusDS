cmake_minimum_required(VERSION 3.9)
project(cplus)

set(CMAKE_CXX_STANDARD 17)

#add_executable(cplus linear/singlelistmain.cpp)
#add_executable(cplus leetcode/linear/array/main.cpp )
#add_executable(cplus linear/seqmain.cpp)
#设立尾指针的单循环链表
#add_executable(cplus linear/singlecircletaillistmain.cpp)
#------------------栈-------------------
#add_executable(cplus stack&queue/seqstackmain.cpp)
#add_executable(cplus stack&queue/seqstackmainChar.cpp array/c5-1.h array/bo5-1.cpp)
#------------第五章-数组-----------------------
#add_executable(cplus array/main5-1.cpp )
#add_executable(cplus array/main5-2.cpp)
#-------------第六章-树-----------
#add_executable(cplus array/main5-2.cpp Tree/c6-1.h Tree/bo6-1.cpp dp/coin.cpp)
#-------------动态规划-硬币问题----------
#add_executable(cplus dp/coin.cpp )
#-------------动态规划-硬币问题----------
#add_executable(cplus dp/package.cpp)
#-------------动态规划-背包问题----------
#add_executable(cplus dp/chardistance.cpp )
add_executable(cplus  dp/lis.cpp)

