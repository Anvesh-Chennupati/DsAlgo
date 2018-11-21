#include<iostream>

using namespace std;

int main(){
    cout<<"\n Enter value of N: ";
    int N;
    cin>>N;
    int deno[] = {1,5,10,25};
    int count[] = {0,0,0,0};
    while(N>0){
        for(int i = 3;i>=0;i--){
            if(deno[i]<=N){
                N = N - deno[i];
                count[i]++;
            }
        }
    }
    cout<<"Denominations :"<<endl;
    for(int i = 0;i<4;i++){
        cout<<deno[i] <<"-> "<<count[i]<<endl;
    }
}