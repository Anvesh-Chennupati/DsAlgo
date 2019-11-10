// Example program
#include <iostream>
#include <string>
#include <vector>
#include<bits/stdc++.h>
using namespace std;

int segment(int x, vector<int> arr)
{
    int maxVal =-1;
    for(int i=0; i + x< arr.size(); i++){
        int minSoFar = INT_MAX;
        for(int j =i; j < i+ x; j++){
            if(arr[j] < minSoFar) minSoFar = arr[j];
            }
            maxVal = max(maxVal, minSoFar);
        }
        return maxVal;
}

int main()
{
    vector<int> arr{1,2,3,1,2};
    std::cout<<segment(1, arr);
}
