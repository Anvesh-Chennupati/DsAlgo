#include<iostream>
#include<vector>
#include <algorithm>    

using namespace std;

void moveZeros(vector<int> &arr){
    if(arr.size()<2) return;
    int _zidx = -1;
    int i=0;
    while(i < arr.size()){
        if(arr[i]==0){
            if(_zidx==-1){
                _zidx = i;
                i++;
            }
            else{
                _zidx = _zidx;
                i++;
            }
        }
        else{
            if(_zidx!=-1){
                swap(arr[i],arr[_zidx]);
                _zidx++;
                i++;
            }else i++;
        }
    }
}

int main(int argc, char** argv){
    vector<int> arr{0,1,0,13,12,5};
    cout<<endl;
    for(auto x:arr) cout<<x<<" ";
    moveZeros(arr);
    cout<<endl;
    for(auto x:arr) cout<<x<<" ";
    return 0;
}