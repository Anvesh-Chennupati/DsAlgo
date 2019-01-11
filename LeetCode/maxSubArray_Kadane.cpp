#include<iostream>
#include<vector>

using namespace std;

class Solution{
    public:

    vector<int> maxSubArray(vector<int> arr){
        int start, end, search;
        start =0;end =0; search =0;
        int maxsofar = arr[0];
        int maxtillhere = 0;

        for(int i=0;i<arr.size();i++){
            maxtillhere = maxtillhere + arr[i];

            if(maxsofar < maxtillhere){
                maxsofar = maxtillhere;
                start = search;
                end =i;
            }

            if(maxtillhere < 0){
                maxtillhere =0;
                search = i+1;
            }
        }
         vector<int> vect2(arr.begin()+start, arr.begin()+end+1); 
         return vect2;
    }
};

int main(){
    vector<int> tc1 = {-2,1,-3,4,-1,2,1,-5,4};
    Solution s;
    vector<int> sol = s.maxSubArray(tc1);
    cout<<"\nElements of subarray: ";
    for(auto x:sol)
        cout<<" "<<x;
    
    int sum = 0;
    for(auto x:sol)
        sum+=x;
    
    cout<<"\nSum of Elements in subarray: ";
    cout<<sum;
}