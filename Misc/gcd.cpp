#include<iostream>

using namespace std;

unsigned int gcdIterative(unsigned int a,unsigned int b){
    unsigned int x = min(a,b);
    unsigned int y = max(a,b);
    while(x > 0){
        unsigned int temp = y;
        y =x;
        x =temp %x;
    }
    return y;
}

unsigned int gcdRecursive(unsigned int a,unsigned int b){

    if (b == 0) 
        return a; 
    return gcdRecursive(b, a % b);
}

int main(){
    unsigned int a,b;
    cin>>a>>b;
    int ans1 = gcdIterative(a,b);
    int ans2 = gcdRecursive(a,b);
    cout<<"\n Recursive :"<<ans1;
    cout<<"\n Iterative :"<<ans2;
}