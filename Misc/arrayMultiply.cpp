#include<iostream>
#include<vector>

using namespace std;

int main(){
    vector<int> arr{0,1,0,1,0,1};
    long product =1;
    int zcount =0;
    for(auto x: arr){
        if(x!=0){
            product*=x;
        }
        else zcount++;
    }
        
}