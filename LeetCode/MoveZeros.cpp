#include<iostream>
#include<vector>

using namespace std;

void pushZeros(vector<int> nums){
    int zind = -1;
        int i = 0;
        int n = nums.size();
        while(i < n){
            if(nums[i] ==0){
                if(zind != -1){
                    zind = zind;
                    i++;
                }
                else{
                    zind = i;
                    i++;
                }
            }
            else 
            {
                if(zind!= -1){
                swap(nums[zind], nums[i]);
                zind++;
                i++;

                }
                else {
                    i++;
                    }

            }
            cout<<"\n";
        for(auto it: nums){
            cout<<it<<" ";
        }
          cout<<"\n";
    }
}

int main(){
    vector<int> nums;
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(0);
    nums.push_back(3);
    nums.push_back(12);
    pushZeros(nums);
    // for(auto it: nums){
    //   cout<<it<<" ";
    //}
}
