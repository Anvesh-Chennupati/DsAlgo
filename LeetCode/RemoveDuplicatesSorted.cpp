#include<iostream>
#include<vector>
using namespace std;

int main(){
    int nums[] = {1,2,2,3,4,4,4,5,6,7,7,8,9,9,11,11};
    int n = sizeof(nums)/sizeof(nums[0]);
    if (n== 0) return 0;
    int i = 0;
    for (int j = 1; j < n; j++) {
        if (nums[j] != nums[i]) {
            i++;
            nums[i] = nums[j];
        }
    }
    for(int k =0;k<i+1;k++){
        cout<<nums[k];
    }

    }
 
