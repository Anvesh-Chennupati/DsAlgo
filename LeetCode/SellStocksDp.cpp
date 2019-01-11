#include<iostream>
#include<vector>


using namespace std;

class Solution{
    public:

    int findProfit(vector<int> arr){

        vector<int> prof(arr.size(),0);
        for(int i=0;i<arr.size();i++){
            int maxsum = 0;
            for(int j = i+1;j<arr.size();j++){
                if(arr[j] > arr[i] && (arr[j] - arr[i]) >=maxsum){
                    maxsum = arr[j] - arr[i];
                }
            }
            prof[i] = maxsum;
        }
        int max =0;

        for(auto x:prof){
            cout<<" "<<x;
            if(max <= x){
                max = x;
            }
        }
        cout<<endl;
        return max;

    }
};

int main(){
    vector<int> v1 = {7,1,5,3,6,4};
    vector<int> v2 = {7,6,4,3,1};
    Solution s1;
    cout<<s1.findProfit(v1)<<endl;
    cout<<s1.findProfit(v2);
}
