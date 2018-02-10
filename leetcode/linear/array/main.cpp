#include <iostream>
#include "removeDuplicates.cpp"
using namespace std;

void printArray(int a[], int n){
    //int n=sizeof(a)/sizeof(a[0]);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}

int main(){

    cout<<"--------remove duplicates----------"<<endl;
    int a[5]={1,1,2,2,3};
    int index=0;
    int n=sizeof(a) / sizeof(a[0]);

    RemoveDuplicates rd = RemoveDuplicates();
    //index= rd.removeDuplicates1(a, n);
    //cout<<index<<endl;
    //printArray(a, index);

    //rd.removeDuplicates2(a,n);
    cout<<rd.removeDuplicates3(a,n);

}