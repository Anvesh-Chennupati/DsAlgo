#include<iostream>
#include<vector>
using namespace std;

vector<int> MinMax(int arr[],int lo,int hi){
        vector<int> ans;
        vector<int> mf;
        vector<int> ms;
        if(hi-lo<=1){
                ans.push_back(arr[lo]);
                ans.push_back(arr[hi]);
                return ans;
        }
        else{
                ans.clear();
                mf.clear();
                ms.clear();
                int mid = lo + (hi-lo)/2;
                cout<<"lo: "<<lo<<" hi: "<<hi<<" mid: "<<mid;
                int m1,M1,m2,M2;
                vector<int> mf;
                vector<int> ms;
                mf = MinMax(arr,lo,mid);
                ms = MinMax(arr,mid+1,hi);
                m1 = mf[0];M1 = mf[1];
                m2 = ms[0];M2 = ms[1];
                cout<<"m1: "<<m1<<" M1: "<<M1<<" m2: "<<m2<<" M2: "<<M2<<endl;
                int m = (m1 < m2) ? m1 : m2;
                int M = (M1 > M2) ? M1 : M2;
                ans.push_back(m);
                ans.push_back(M);
                return ans;
        }
}

int main(){
    int arr[] = {19,12,4,67,45,33,98,76,1,22,2};
    //int arr[] = {5,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> v1;
    v1 = MinMax(arr,0,n);
    cout<<"min: "<<v1[0]<<" max: "<<v1[1];
}