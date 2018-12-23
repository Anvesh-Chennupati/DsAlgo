#include<iostream>

using namespace std;

int main(){
    int nums1[] = {1,2,3,0,0,0};
    int nums2[] = {2,5,6};
    int m = 3;
    int n = 3;


    // cout<<"\n";
    //         for(int i =0;i<sizeof(arr1)/sizeof(arr1[0]);i++){
    //             // cout<<"\n here";
    //         for(int j=0;i<n;j++){
    //             // cout<<"\n here";
    //             if(arr1[i] <= arr2[j]){
    //                 break;
    //             }
    //             else{
    //                 int temp = arr1[i];
    //                 arr1[i] = arr2[j];
    //                 arr2[j] = temp;
    //                 break;
    //             }
    //         }
            
    //     }
        
    //     for(int i=sizeof(arr1)/sizeof(arr1[0]) -m,j=0;i<sizeof(arr1)/sizeof(arr1[0]);i++){
    //     arr1[i] = arr2[j++];
    //     }
    
        int i = m - 1, j = n - 1, tar = m + n - 1;
        while (j >= 0) {
            nums1[tar--] = (i >= 0 && nums1[i] > nums2[j]) ? nums1[i--] : nums2[j--];
        }


        for(int i =0;i<sizeof(nums1)/sizeof(nums1[0]);i++){
        cout<<" "<<nums1[i];
    }

}