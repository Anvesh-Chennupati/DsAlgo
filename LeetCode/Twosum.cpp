#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
//have to fix this

vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> answer;
        unordered_map<int,int> numIndex;
        for(int i =0; i<nums.size();i++){
            numIndex[nums[i]] = i;
        }
        
        for(int i =0; i< nums.size(); i++){
            int diff = target - nums[i];
            if(numIndex.find(diff)!= numIndex.end() && i!=numIndex[diff]){
                answer.push_back(i);
                answer.push_back(numIndex[diff]);
                return answer;
            }
            // else continue;
        }
        return answer;
    }
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
            cout<< it.second<<"->" << comp;
        }
    }

}