#include<iostream>

using namespace std;

void Merge(){

}

void MergeSort(int arr[],int l, int m1,int m2,int r){
    cout<<" left: "<<l;
    cout<<" middle1: "<<m1;
    cout<<" middle2: "<<m2;
    cout<<" right: "<<r<<"\n";

//    MergeSort(arr,)

}

int main(int argv, char* argc[]){
    int arr[] = {9,8,7,6,5,4,3,2,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    MergeSort(arr,0,n/3,2*n/3,n);
    return 0;
}