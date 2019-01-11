#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
 
class Solution {
public: 
     int maxProfitR(vector<int> houses){
         vector<int> tempsol(houses.size(),0);
         for(int i=0;i<houses.size();i++){
             int tempprofit = houses[i];
             for(int j= i+2;j<houses.size();j+=2){
                 tempprofit += houses[j];
             }

             tempsol[i] = tempprofit;
         }
         return *max_element(tempsol.begin(),tempsol.end());
     }

     int maxProfitDP(vector<int> nums){
         int include =0;
         int exclude = 0;

         for(int j =0;j<nums.size();j++){
             int temp = include;
             include = nums[j] + exclude;
             exclude = max(exclude,temp);
         }

         return max(include,exclude);  
     }

};
 
int main(int argc, char const *argv[]) {
    vector<int> houses = {2,7,9,3,1};
    Solution s1;
    cout<<"\nMax profitR: "<<s1.maxProfitR(houses);

    cout<<"\nMax profitDP: "<<s1.maxProfitDP(houses);
    return 0;
}