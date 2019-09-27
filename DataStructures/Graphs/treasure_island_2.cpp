/*
You have a map that marks the locations of treasure islands. Some of the map area has jagged rocks and dangerous reefs. Other areas are safe to sail in. There are other explorers trying to find the treasure. So you must figure out a shortest route to one of the treasure islands.

Assume the map area is a two dimensional grid, represented by a matrix of characters. You must start from one of the starting point (marked as S) of the map and can move one block up, down, left or right at a time. The treasure island is marked as X. Any block with dangerous rocks or reefs will be marked as D. You must not enter dangerous blocks. You cannot leave the map area. Other areas O are safe to sail in. Output the minimum number of steps to get to any of the treasure islands.

Example:

Input:
[['S', 'O', 'O', 'S', 'S'],
 ['D', 'O', 'D', 'O', 'D'],
 ['O', 'O', 'O', 'O', 'X'],
 ['X', 'D', 'D', 'O', 'O'],
 ['X', 'D', 'D', 'D', 'O']]

Output: 3
Explanation:
You can start from (0,0), (0, 3) or (0, 4). The treasure locations are (2, 4) (3, 0) and (4, 0). Here the shortest route is (0, 3), (1, 3), (2, 3), (2, 4).

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