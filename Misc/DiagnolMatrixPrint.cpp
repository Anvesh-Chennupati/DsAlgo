#include<iostream>
#include<vector>

using namespace std;

int main(){
    vector< vector<int> > v1 { { 1, 2 }, 
                               { 4, 5, 6 }, 
                               { 7, 8, 9, 10 },
                               {1,2,3,4,54,5} }; 
    int nrows = v1.size();
        int ncols = 0;
        for(int i = 0;i<nrows;i++){
            int temp = v1[i].size();
            if(temp >ncols)
                ncols = temp;
        }
        cout<<"\n rows "<< nrows;
        cout<< "\n max cols "<<ncols;
    /*
    for(int i =0; i<v1.size(); i++){
        cout<<"\n";
        for(int j=0;j<v1[i].size(); j++){
            cout<<" "<<v1[i][j];
        }
    }
    /*
    vector< vector<int> > v2;
    cout<<"\n Enter number of rows";
    int rw,cl;
    cin>>rw;
    cout<<"\n Enter number of columns";
    cin>>cl;
    cout<<"\n Enter the elements";
    for(int i =0;i<rw;i++){
        cout<<"\n Elements in "<<i<< "row:";
        for(int j = 0; j< cl;j++){
            cin>>v2[i][j];
        }
    }
    cout<<v2.size();
    */
}
