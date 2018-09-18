//Program to sort array.

#include<iostream>

using namespace std;

void printArray(int arr[],int n){
cout<<"\n";
for(int i =0;i<n;i++){
    cout<<" "<<arr[i];
}
}

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void SelectionSort(int arr[],int n){
int i,j,min_ind;

for(i=0;i<n-1;i++){

    min_ind = i;

    for(j =i+1; j<n; j++){
        if(arr[j] < arr[min_ind])
            min_ind = j;}   
        swap(&arr[min_ind],&arr[i]);

}
}

int main(){

int arr[] = {64, 25, 12, 22, 11};
int length = sizeof(arr)/sizeof(arr[0]);
cout<<"\n Unsorted Array:";
printArray(arr,length);
SelectionSort(arr,length);
cout<<"\n Sorted Array:";
printArray(arr,length);
}