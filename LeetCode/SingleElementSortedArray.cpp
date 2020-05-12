#include<iostream>
#include<vector>

using namespace std;

class Solution{
    public:
    int singleNonDuplicate(vector<int> nums){
        int lo = 0;
        int hi = nums.size() - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            bool halvesAreEven = (hi - mid) % 2 == 0;
            if (nums[mid + 1] == nums[mid]) {
                if (halvesAreEven) {
                    lo = mid + 2;
                } else {
                    hi = mid - 1;
                }
            } else if (nums[mid - 1] == nums[mid]) {
                if (halvesAreEven) {
                    hi = mid - 2;
                } else {
                    lo = mid + 1;
                }
            } else {
                return nums[mid];
            }
        }
        return nums[lo];
    }

};

int main(){
    Solution s;
    vector<int> t1{1,1,2,2,3,3,4,8,8};
    vector<int> t2{3,3,7,7,10,11,11};
    vector<int> t3{1,2,2};
    cout<<s.singleNonDuplicate(t1)<<endl;
    cout<<s.singleNonDuplicate(t2)<<endl;
    cout<<s.singleNonDuplicate(t3)<<endl;
}