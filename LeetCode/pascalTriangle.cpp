#include<iostream>
#include<vector>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<vector<int>> result;
    cout<<"\nEnter n";
    int numRows;
    cin>>numRows;

    if(numRows<1){
        cout<<"\nNothing";
    }
    else{
        result.push_back({1});
        result.push_back({1,1});
        int j = 3;
        numRows;
        while(--numRows){
            vector<int> temp = result.back();
            vector<int> curr(j,1);
            for(int i=1;i<temp.size();i++){
                curr[i] = temp[i] + temp[i-1];
            }

            result.push_back(curr);
            temp.resize(0);
            curr.resize(0);

            j++;
        }
    }

    result.pop_back();
    for(auto x:result){
        cout<<endl;
        for(int i=0;i<x.size();i++){
            cout<<x[i];
        }
    }
    return 0;
}
