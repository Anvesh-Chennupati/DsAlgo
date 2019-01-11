#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
 
class Solution {
public: 
     int maxProfit(vector<int> houses){
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
};
 
int main(int argc, char const *argv[]) {
    vector<int> houses = {2,7,9,3,1};
    Solution s1;
    cout<<"\nMax profit: "<<s1.maxProfit(houses);
    return 0;
}