#include<iostream>
#include<vector>

using namespace std;

class Solution{
    public:
    int nr;
    int nc;
    int numberIslands(vector<vector<int> > &grid){
        int ans =0;
        this->nr = grid.size();
        this->nc = grid[0].size();
        for(int i=0; i <nr; i++){
            for(int j= 0; j<nc; j++){
                // cout<<"Here"<<i<<j<<endl;
                ans+= grid[i][j];
                // cout<<"i "<<i; cout<<j;
                dfsUTIL(i,j,grid);
            }
        }

        
        return ans;
    }

    void dfsUTIL(int i, int j,vector<vector<int> > &grid){
        if(i < 0 || j <0 || i >=nr || j>= nc || grid[i][j] == 0) return;
        // cout<< nr<<" "<<nc<< " "<< i<<" "<<j<<endl;
        grid[i][j] = 0;
        dfsUTIL(i+1,j,grid);
        dfsUTIL(i-1,j,grid);
        dfsUTIL(i,j+1,grid);
        dfsUTIL(i,j-1,grid);

    }
};

int main(){
    Solution s1;
    vector<vector<int>> grid = {{0,0,1,1,1},
                                {1,1,1,0,0},
                                {0,1,0,0,0},
                                {1,1,1,1,1}};
    cout<<s1.numberIslands(grid);
    return 0;
}