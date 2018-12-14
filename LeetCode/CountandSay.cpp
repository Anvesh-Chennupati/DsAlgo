#include<iostream>

using namespace std;

int main(){
    cout<<"\n Enter n: ";
    int n;
    cin>>n;
    if (n == 0) cout<< " ";

    string res = "1";
    while (--n) {
        string cur = "";
        for (int i = 0; i < res.size(); i++) {
            int count = 1;
             while ((i + 1 < res.size()) && (res[i] == res[i + 1])){
                count++;    
                i++;
            }
            cur += to_string(count) + res[i];
        }
        res = cur;
    }
    cout<<res;
}