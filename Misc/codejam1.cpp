#include<iostream>

using namespace std;

int main(){
    int arr[] = {10,15,5,12,40,55,1,10,25,35,45,50,20,28,27,35,15,40,4,5};
    int city1 = 5;
    int city2 = 10;
    int city3 = 27;
    int nbus1 =0;
    int nbus2 = 0;
    int nbus3 = 0;
    for(int i = 0; i< sizeof(arr)/sizeof(arr[0]);i+=2){
        if(city1>=arr[i] && city1<= arr[i+1] )
            nbus1++;
    }
    cout<<nbus1<<" ";
    for(int i = 0; i< sizeof(arr)/sizeof(arr[0]);i+=2){
        if(city2>=arr[i] && city2<= arr[i+1] )
            nbus2++;
    }
    cout<<nbus2<<" ";
    for(int i = 0; i< sizeof(arr)/sizeof(arr[0]);i+=2){
        if(city3>=arr[i] && city3<= arr[i+1] )
            nbus3++;
    }
    cout<<nbus3<<" ";
    
}