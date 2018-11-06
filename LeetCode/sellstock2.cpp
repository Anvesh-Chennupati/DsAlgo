#include<iostream>

using namespace std;

int main(){
    //int arr[] = {7,1,5,3,6,4};
    int arr[] = {7,6,4,3,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    int profit = 0;
    int c1,c2,c3;
    for(int i =1;i<n;i++){
        if(arr[i-1]>arr[i]){
            profit +=0;

        }
        else{
            c1 = arr[i];
            c2 = arr[i-1];
            //cout<<"c1 :"<<c1;
            //cout<<"c2 :"<<c2<<endl;
            profit += c1-c2;
        }
    }
    cout<<profit;
}