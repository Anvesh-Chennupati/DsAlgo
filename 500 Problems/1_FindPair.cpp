//Find all the  pairs with given sum in an unsorted array
#include<iostream>
#include<algorithm>

using namespace std;

void searchPair(int arr[],int size, int number){
sort(arr,arr +size);
int low =0,high= size-1;
while(low<high){
    if(arr[low] + arr[high] ==number){
        cout<<"Pair found "<<arr[low]<<"and "<<arr[high];
        return;
    }
    (arr[low] + arr[high] < number) ? low++:high--;
}
cout<<"Pair not found ";
}

int main(){
    int arr[] = {1,4,8,3,9,10,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int number;
    cin>>number;
    searchPair(arr,n,number);
}