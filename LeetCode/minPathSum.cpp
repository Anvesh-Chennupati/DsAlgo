#include<iostream>
#include<vector>

using namespace std;

class Solution{
    public:
    int helper(vector<vector<int>> grid,int i,int j){
        if(i==grid.size() || j== grid[0].size()) return INT32_MAX;
        if(i==grid.size()-1 && j== grid[0].size()-1 ) return grid[i][j];
        return grid[i][j] + min(helper(grid,i+1,j),helper(grid,i,j+1));
    }

    int RminPathSum(vector<vector<int>> grid){
        return helper(grid,0,0);
    }

    int dpMinPathSum(vector<vector<int>> grid){
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n, 0));

        for (int i = grid.size() - 1; i >= 0; i--) {
            for (int j = grid[0].size() - 1; j >= 0; j--) {
                if(i == grid.size() - 1 && j != grid[0].size() - 1)
                    dp[i][j] = grid[i][j] +  dp[i][j + 1];
                else if(j == grid[0].size() - 1 && i != grid.size() - 1)
                    dp[i][j] = grid[i][j] + dp[i + 1][j];
                else if(j != grid[0].size() - 1 && i != grid.size() - 1)
                    dp[i][j] = grid[i][j] + min(dp[i + 1][j], dp[i][j + 1]);
                else
                    dp[i][j] = grid[i][j];
            }
        }
        return dp[0][0];
    }

};

int main(){
    cout<<"\nMin Path Sum\n";
    vector<vector<int>> g1 {{1,3,1},
                            {1,5,1},
                            {4,2,1}};
    
    vector<vector<int>> g2 {{1,3,4,8},
                            {3,2,2,4},
                            {5,7,1,9},
                            {2,3,2,3}};
    Solution s;
    cout<<s.RminPathSum(g1)<<endl; //time complexity pow(2,(m+n))
    cout<<s.RminPathSum(g2)<<endl;
    cout<<s.dpMinPathSum(g1)<<endl;//time complexity (mn)
    cout<<s.dpMinPathSum(g2)<<endl;
    return 0;
}