#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

vector<vector<int>> searchMatrixModified(vector<vector<int>> matrix, int target) {
    if(matrix.size() == 0 || matrix[0].size() == 0) return matrix;
    
    //Start at top right and bottom left
    int row = matrix.size()-1, col = matrix[0].size()-1;
    
    //Shift columns
    while(matrix[0][col] >= target || col == 0) {
        col--;
    }
    
    //Shift rows
    while(matrix[row][0] >= target || row == 0) {
        row--;
    }
    
    vector<vector<int>> res;
    unordered_map<int, bool> used;
    
    for(int i = 0; i <= row; i++) {
        for(int j = 0; j <= col; j++) {
            if(matrix[i][j] >= target) continue; //Value too large
            int complement = target-matrix[i][j];
            if(used.find(complement) != used.end()) {
                if(!used[complement]) {
                    res.push_back({matrix[i][j], complement});
                    used[matrix[i][j]] = true;
                    used[complement] = true;
                } 
            } else {
                used[matrix[i][j]] = false;
            }
        }
    }
    
    return res;
}

int main(){
    vector<vector<int> > matrix{{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
    int target = 9;
    vector<vector<int> > res = searchMatrixModified(matrix,target);
    for(auto x:res){
        cout<<endl;
        for(auto y: x){
            cout<<y<<" ";
        }
    }
    return 0;
}