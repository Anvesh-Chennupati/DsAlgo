#include<iostream>
#include<vector>
using namespace std;

static int pways =0;

int oddJump(int arr[],int n){
    int indi = -1;
    for(int i=i;i<n;i++){
        if(arr[i]>arr[0]){
            return i;
        }
    }
    return -1;
}

int evenJump(int arr[],int n){
    int indi = -1;
    for(int i=i;i<n;i++){
        if(arr[0]>arr[i]){
            return i;
        }
        else continue;
    }
    return -1;
}

int main(){
    int arr[] = {10,13,12,14,15};
    vector<int> indices;
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i =0;i<n;i++){
        if(i == n-1){
            pways++;
            indices.push_back(i);
        }
        else{
            int oddi = oddJump(arr,n-i);
            cout<<"odd index"<<oddi<<endl;
            if(oddi ==-1) continue;
            int eveni = evenJump(arr+oddi,n-oddi);

            if(eveni==n-1)
                pways++;
        }
    }

    cout<<pways;
}