#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>> processor;
        vector<vector<string>> ans;
        for(auto x:strs){
            string qq = x;
            sort(qq.begin(),qq.end());
            processor[qq].push_back(x);
        }
        
        for(auto x:processor){
            vector<string> temp;
            for(auto y: x.second){
                temp.push_back(y);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};

int main(){
    vector<string> set1 = {"eat", "tea", "tan", "ate", "nat", "bat"};
    Solution s;
    for(auto x: s.groupAnagrams(set1)){
        for(auto y:x){
            cout<<y<<" "; 
        }
        cout<<endl;
    }
    return 0;
}