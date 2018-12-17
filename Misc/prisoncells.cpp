#include<iostream>

using namespace std;
int main(){
    int a[] = {0,1,0,1,1,0,0,1};
     for(auto x:a)
            cout<<" "<<a[x];
    int N = 100;
    int size = sizeof(a)/sizeof(a[0]);
    while(N--){
        for(int i=0;i<size;i++){
            if(i == 0 || i == size-1) continue;

            a[i] = a[i-1] ^ a[i+1];
        }
        cout<<"\n";
    }
}