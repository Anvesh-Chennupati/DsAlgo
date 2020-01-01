#include<iostream>
#include<vector>
#include<algorithm>
#include<bits/stdc++.h>

using namespace std;

void KnapsackF(vector<double> &weights, vector<double>& profits, double TargetWeight){
    vector<double> fractions(weights.size(),0), profitPerW(weights.size(), 0);
    double maxProfit(0);
    for(int i=0; i< weights.size(); i++){
        profitPerW[i] = profits[i]/weights[i];
    }
    // sort(profitPerW.begin(),profitPerW.end(), greater<>());
    //debug message: to print profit per weight
    // for(auto x:profitPerW)
    //     cout<<" "<<x;
    double max_val = *max_element(profitPerW.begin(),profitPerW.end());
    cout<< max_val;
    auto val = find(profitPerW.begin(), profitPerW.end(), 6);
    int index = distance(profitPerW.begin(), val);
    // cout<<endl;
    // cout<<index;
    // profitPerW.erase(val);
    // cout<<endl;
    // for(auto x:profitPerW)
    //     cout<<" "<<x;

    for(int i=0; i< profitPerW.size() && TargetWeight >0; i++){
        // if()
    }
    
}

int main(int argc, char* argv[]){
    vector<double> weights{2,3,5,7,1,4,1};
    vector<double> profits{10,5,15,7,6,18,3};
    KnapsackF(weights,profits, 25);
    return 0;
}