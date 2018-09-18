#include<iostream>

using namespace std;

void printArray(int arr[],int n){
    for(int i=0; i<n; i++){
        cout<<" "<<arr[i];
    }
}

void InsertionSort(int arr[],int n){
    int i,j,key;
    for(j=1;j<n;j++){
        key = arr[j];
        i = j-1;
        while(i>=0 && arr[i]>key){
            arr[i+1] = arr[i];
            i = i-1;
        }
        arr[i+1] = key;
    }
}

int main(){
    int arr[] = {9,8,7,6,5,4,3,2,1};
    cout<<"\n Unsorted Array: ";
    int n = sizeof(arr)/sizeof(arr[0]);
    printArray(arr,n);
    cout<<"\n Sorted Array: ";
    InsertionSort(arr,n);
    printArray(arr,n);
}