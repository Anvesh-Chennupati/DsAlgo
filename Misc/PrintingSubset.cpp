#include<iostream>

using namespace std;

// void printSubset(int *ptr){
//     int **p = *ptr;
//     cout<<**p;
// }
int main(){
    int arr[] = {1,2,3};
    int *p[] = {arr, arr+1, arr+2};
    int **pp = p;

    cout<<pp<<endl;
    cout<<(**pp)<<endl;
    cout<<(*p)<<endl;
    //printSubset(p);
    //printSubset(p);
}