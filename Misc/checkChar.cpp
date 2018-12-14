#include<iostream>

using namespace std;

int main(){
    string s = "   x-12l3zxc";
//     for(auto x:s)
//         cout<<(int)s[x];

int res = 0;
for(int i =0; i <s.length();i++){
        if(s[i]>='0' && s[i]<='9'){
                res = res *10 + s[i] - '0';
        }

}
cout<<res;
}