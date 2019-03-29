#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int f1 = 0; //(n-1)th Stairs cost
        int f2 = 0; //(n-2)th Stairs cost
        int res;
        for (int i = 2; i <= cost.size(); ++i) {
            cout<<"before F1: "<<f1<<"\tF2: "<<f2<<endl;
            res = min(f1+cost[i-1], f2+cost[i-2]);
            f2 = f1;
            f1 = res;
            cout<<"after F1: "<<f1<<"\tF2: "<<f2<<"\t res: "<<res<<endl;
        }
        return res;
    }
};

int main(){
    Solution s1;
    vector<int> cost = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    cout<<s1.minCostClimbingStairs(cost);
}