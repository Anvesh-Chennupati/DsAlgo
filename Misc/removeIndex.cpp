#include<iostream>

using namespace std;

int main(int argc, char** argv){
    int arr[] = {1,2,3,4,5,6,7,8,9};
    for(int i=0; i< 9; i++){
        cout<<" "<<arr[i];
    }
    cout<<endl;
    int rarr[8];
    for(int i=0; i<8;i++){
        rarr[i] = arr[i];
        if(i>=4){
            rarr[i] = arr[i+1];
        }
        // else{
        //     // rarr[i] = arr[i];
        // }
        
    }
    for(int i=0; i< 8; i++){
        cout<<" "<<rarr[i];
    }
}