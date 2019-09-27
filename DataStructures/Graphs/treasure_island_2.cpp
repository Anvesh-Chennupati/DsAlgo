/*
You have a map that marks the location of a treasure island. Some of the map area has jagged rocks and dangerous reefs. Other areas are safe to sail in. There are other explorers trying to find the treasure. So you must figure out a shortest route to the treasure island.
Assume the map area is a two dimensional grid, represented by a matrix of characters. You must start from the top-left corner of the map and can move one block up, down, left or right at a time. The treasure island is marked as X in a block of the matrix. X will not be at the top-left corner. Any block with dangerous rocks or reefs will be marked as D. You must not enter dangerous blocks. You cannot leave the map area. Other areas O are safe to sail in. The top-left corner is always safe. Output the minimum number of steps to get to the treasure.
Example:
Input:
[['O', 'O', 'O', 'O'],
 ['D', 'O', 'D', 'O'],
 ['O', 'O', 'O', 'O'],
 ['X', 'D', 'D', 'O']]

Output: 5
Explanation: Route is (0, 0), (0, 1), (1, 1), (2, 1), (2, 0), (3, 0) The minimum route takes 5 steps.

*/
#include<iostream>
#include<vector>
#include<list>

using namespace std;

vector<vector<int> > directions {{1,0}, {0,1},{-1,0}, {0,-1}};

class Point{
    public:
    int x;
    int y;
    Point(int x, int y){
        this->x = x;
        this->y = y;
    }
    void PrintPoint(){
        cout<<"["<<x;
        cout<<","<<y<<"]";
    }
};
bool isSafe(vector<vector<char> > grid,int r, int c){
    return r >= 0 && r < grid.size() && c >= 0 && c < grid[0].size() && grid[r][c] != 'D';
}

list<Point> findSources(vector<vector<char> > grid){
    list<Point> sources;
    for(int i=0; i< grid.size();i++){
        for(int j= 0; j <grid[0].size();j++){
            if(grid[i][j] == 'S'){
                sources.push_back(Point(i,j));
            }
        }
    }
    return sources;
}

int minimumStep(vector<vector<char> > grid){
    list<Point> q;
    // q.push_back(Point(0,0));
    q = findSources(grid);
    grid[0][0] = 'D';
    for (int steps = 1; !q.empty(); steps++) {
        /*cout<<"\nsteps value: "<<steps;                     //fordebugging
        cout<<"\nitems in current queue: ";
        list<Point>::iterator it;
        for(it = q.begin(); it!= q.end();it++){
            Point temp = *it;
            temp.PrintPoint();
        }*/
        for (int sz = q.size(); sz > 0; sz--) {
            Point p = q.front();
            q.pop_front();
            for (auto x : directions) {
                int r = p.x + x[0];
                int c = p.y + x[1];
                
                if (isSafe(grid, r, c)) {
                    if (grid[r][c] == 'X') return steps;
                    grid[r][c] = 'D';
                    q.push_back(Point(r, c));
                }
            }
        }
    }
    return -1;
}

int main(int argc, char** argv){
    vector<vector<char> > grid{ {'S', 'O', 'O', 'S', 'S'},
                                {'D', 'O', 'D', 'O', 'D'},
                                {'O', 'O', 'O', 'O', 'X'},
                                {'X', 'D', 'D', 'O', 'O'},
                                {'X', 'D', 'D', 'D', 'O'}};
    int steps = minimumStep(grid);

    if(steps!= -1)
        cout<<"\nMinimum steps to Treasure: "<<steps;
    else cout<<"Cannot find the treasure";
    return 0;
}