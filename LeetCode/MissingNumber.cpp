#include<iostream>

using namespace std;

int main(){
    int arr[] = {0,1,2,3,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<n<<endl;
    int sum = ((n)*(n+1))/2;
    int arrsum =0;
    for(int i =0;i<n;i++){
        arrsum+=arr[i];
    }
    cout<<sum - arrsum;
}