#include<iostream>
#include<vector>

using namespace std;

void inc(int* arr,int n){
    for(int i=0; i<n;i++){
        arr[i]++;
    }
}

int main(int argc,char** argv){
    int arr[] = {1,2,3,4,5};
    inc(arr,sizeof(arr)/sizeof(arr[0]));
    for(auto x: arr) cout<<x<<" ";
    return 0;
}