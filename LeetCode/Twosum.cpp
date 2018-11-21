#include<iostream>
#include<unordered_map>
using namespace std;
//have to fix this
int main(){
    int arr[] = {2, 7, 11, 15};
    int num = 9;
    int n = sizeof(arr)/sizeof(arr[0]);
    unordered_map <int,int> m1;
    for(int i = 0;i<n;i++){
        m1[arr[i]] = i;
    }
    for(auto it:m1){
        int comp = num - it.first;
        if(m1.find(comp)!= m1.end()){
            cout<< it.second << comp;
        }
    }

}