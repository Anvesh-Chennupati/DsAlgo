#include<iostream>
#include<bitset>

using namespace std;

int main(){
    uint32_t n;
    n  = 15;
    int res = 0;

    while(n){
        cout<<"bitset n \t"<<bitset<32>(n)<<endl;
        cout<<"bitset n-1 \t"<<bitset<32>(n-1)<<endl;
        n&=n-1;
        cout<<"bitset n&n-1 \t"<<bitset<32>(n)<<endl;
        //cout<<n<<endl;
        res++;
    }
    cout<<res;
}