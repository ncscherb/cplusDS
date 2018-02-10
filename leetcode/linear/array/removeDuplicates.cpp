/*
2.1.1 Remove Duplicates from Sorted Array
Given a sorted array, remove the duplicates in place such that each element appear only once
and return the new length.
Do not allocate extra space for another array, you must do this in place with constant memory.
For example, Given input array A = [1,1,2],
Your function should return length = 2, and A is now [1,2].
 */

#include <algorithm>
#include <iostream>

class RemoveDuplicates{
public:
    int removeDuplicates1(int *a, int n){
        if(n==0)
            return 0;
        int index=1;

        for(int i=1;i<n;i++){
            if(a[i]!=a[i-1]){
                a[index++]=a[i];
            }
        }

        return index;
    }

    int removeDuplicates2(int a[], int n){
        //unique:对有序的容器重新排列，将第一次出现的元素从前往后排，其他重复出现的元素依次排在后面
        //a表示数组的起始位置，a+n时数组的结束位置
        //返回的是重新排列后不重复元素结束位置后一个元素的指针
        int *begin = std::unique(a,a+n);
        //返回a和begin之间元素的个数，包括a但是不包括begin
        int index=std::distance(a,begin);

        return index;
    }

    int removeDuplicates3(int a[],int n){
        return removeDuplicates3(a,a+n,a)-a;
    }

    template <typename InIt, typename OutIt>
    OutIt removeDuplicates3(InIt first, InIt last, OutIt output){
        while (first!=last){
            *output++=*first;
            //upper_bound返回一个非递减序列[first, last)中的第一个大于值val(*first)的位置。
            first=std::upper_bound(first,last,*first);
        }

        return output;
    };
};
