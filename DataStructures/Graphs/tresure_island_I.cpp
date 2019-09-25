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

int minimumStep(vector<vector<char> > grid){
    list<Point> q;
    q.push_back(Point(0,0));
    grid[0][0] = 'D';
    for (int steps = 1; !q.empty(); steps++) {
        cout<<"\nsteps value: "<<steps;
        cout<<"\nitems in current queue: ";
        list<Point>::iterator it;
        for(it = q.begin(); it!= q.end();it++){
            Point temp = *it;
            temp.PrintPoint();
        }
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
    vector<vector<char> > grid{ {'O', 'O', 'O', 'O'},
                                {'D', 'O', 'D', 'O'},
                                {'O', 'O', 'O', 'O'},
                                {'X', 'D', 'D', 'O'}};
    int steps = minimumStep(grid);

    if(steps!= -1)
        cout<<"\nMinimum steps to Treasure: "<<steps;
    else cout<<"Cannot find the treasure";
    return 0;
}