#include<iostream>
#include<vector>
#include<cmath>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<vector<int> > result;
        unordered_map<double,vector<int>> map;
        for(int i=0; i< points.size(); i++){
            map[Edistance(points[i])] = points[i];
        }

        // for(auto it = map.begin(); it != map.end(); ++it){
        //     cout<<"\n";
        //     cout<<it->first<<"->"<<it->second[0]<<":"<<it->second[1];
        // }    //printing the map
        vector<double> sortedKeys;
        sortedKeys.reserve(map.size());
        for(auto& it:map)
            sortedKeys.push_back(it.first);
        std::sort(sortedKeys.begin(),sortedKeys.end());

        // for(auto x:sortedKeys) cout<<x<<" "; //printing out keys

        for(int i =0; i< K; i++){
            result.push_back(map[sortedKeys[i]]);
        }
        return result;

    }
    double Edistance(vector<int> point){
        double val =  sqrt(pow(point[0],2) + pow(point[1],2));
        return val;
    }
};

int main(int argc, char** argv){
    vector<vector<int> > points{{-16, 5}, {-1, 2}, {4, 3}, {10, -2}, {0, 3}, {-5, -9}};
    Solution s1;
    vector<vector<int> > sol = s1.kClosest(points,3);
    for(int i=0; i< sol.size();i++){
        cout<<"\n";
        
    cout<<"["<<sol[i][0]<<","<<sol[i][1]<<"]";
    }
    return 0;
}