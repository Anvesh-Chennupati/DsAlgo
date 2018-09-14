#include<iostream>

using namespace std;

int main(){
 int x;
 cin>>x;
 int output =1;
 while(x>=1){
     output = output * x;
     x--;
 }
 cout<<output;
}