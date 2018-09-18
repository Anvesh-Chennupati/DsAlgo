#include<iostream>

using namespace std;

void printArray(int arr[],int n){
    for(int i=0; i<n; i++){
        cout<<" "<<arr[i];
    }
}

void Merge(int arr[],int l,int m,int r){
    int i,j,k,n1,n2;
    n1 = m+1 -l;
    n2 = r - m;
    int L[n1], R[n2];
    for( i =0;i<n1;i++){
        L[i] = arr[l+i];
    } 
    for( j =0;j<n2;j++){
        R[j] = arr[m+1+j];
    }
    i=0;j=0;k=l;

    while(i<n1 && j<n2){
        if(L[i]<=R[j]){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while(i<n1){
        arr[k] = L[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}

void MergeSort(int arr[],int l,int r){
    if(l<r){
        int m = ( l+r)/2;
        MergeSort(arr,l,m);
        MergeSort(arr,m+1,r);
        Merge(arr,l,m,r);
    }
}


int main(){
    int arr[] = {9,8,7,6,5,4,3,2,1};
    cout<<"\n Unsorted Array: ";
    int n = sizeof(arr)/sizeof(arr[0]);
    printArray(arr,n);
    cout<<"\n Sorted Array: ";
    MergeSort(arr,0,n);
    printArray(arr,n);
}