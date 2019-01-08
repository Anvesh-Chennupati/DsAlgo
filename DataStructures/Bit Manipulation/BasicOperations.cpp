#include<iostream>
#include<vector>

using namespace std;

class Basic{
    public:

    int xorAll(vector<int> list){
        return xorAll(list,list.size());
    }

    private:
    int xorAll(vector<int> list,int len){
        int va =0;
        for(auto x:list)
            va^=x;

        return va;
    }

};

int main(){
    vector<int> l1 = {1,2,3,4,1,2,3};
    Basic b1;
    cout<<b1.xorAll(l1);
    return 0;
}