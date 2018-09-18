#include<iostream>

using namespace std;

void printArray(int arr[],int n){
    for(int i=0; i<n; i++){
        cout<<" "<<arr[i];
    }
}

void QuickSort(int arr[],int n){

}

int main(){
    int arr[] = {9,8,7,6,5,4,3,2,1};
    cout<<"\n Unsorted Array: ";
    int n = sizeof(arr)/sizeof(arr[0]);
    printArray(arr,n);
    cout<<"\n Sorted Array: ";
    QuickSort(arr,n);
    printArray(arr,n);
}