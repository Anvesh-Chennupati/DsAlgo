#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

void printMatrix(vector<vector<int> >& matrix){
    for(auto x:matrix){
        for(auto y:x){
            cout<<y<<"\t";
        }
        cout<<endl;
    }
}

void diagonalSort(vector<vector<int> >& matrix){
    size_t n = matrix.size();
    //sorting upper diagonal
    for(int i=0; i<n;i++){
        //fetching elements into vector the sorting them
        vector<int> fetchUpperElements;
        vector<int> fetchLowerElements;
        for(int j=0; j<=i; j++){
            fetchUpperElements.push_back(matrix[i-j][j]);
            fetchLowerElements.push_back(matrix[n-i-1+j][n-j-1]);
        }
        std::sort(fetchUpperElements.begin(),fetchUpperElements.end(), greater<int>()); //for decending
        std::sort(fetchLowerElements.begin(),fetchLowerElements.end());
        
        for(int j=0; j<=i; j++){
            matrix[i-j][j] = fetchUpperElements[j];
            matrix[n-i-1+j][n-j-1] = fetchLowerElements[j];
        }
    }
}

int main(int argv, char* argc[]){
    vector<vector<int> > matrix{{12,4,2,7,3},
                                {3,10,25,1,7},
                                {8,1,17,11,20},
                                {13,10,23,24,5},
                                {17,15,19,22,12}};
    printMatrix(matrix);
    diagonalSort(matrix);
    cout<<endl;
    printMatrix(matrix);

}
