cmake_minimum_required(VERSION 3.9)
project(cplus)

set(CMAKE_CXX_STANDARD 17)

#add_executable(cplus linear/singlelistmain.cpp)
#add_executable(cplus leetcode/linear/array/main.cpp )
#add_executable(cplus stack&queue/seqstackmainChar.cpp)
add_executable(cplus linear/seqmain.cpp linear/singlecircletaillist.cpp)

