#include<iostream>
#include<string>
#include<set>
#include<unordered_map>

using namespace std;

set<string> countoneDistinctString(string s1,int k){
    set<string> ans;
    if(s1.size()!=0){
        for(int i =0; i<s1.length();i++){
            string temp = "";
            unordered_map<char,bool> check;
            int dc = 0;
            if(i+k <= s1.length()){
                for(int j =i;j< i+k;j++){
                temp+=s1[j];
                if(check.find(s1[j])!=check.end()){
                    dc++;
                }
                else{
                    check[s1[j]] = true;
                }
            }
            if(dc == 1){
                ans.insert(temp);
            }

            }
            
        }
        return ans;
    }
    else return ans;
}
int main(){
    string s1 = "anaveshahegghydxdtbbbbgfg";
    int k = 5;
    set<string> ans;
    ans = countoneDistinctString(s1,k);
    for(auto x:ans){
        cout<<"\n"<<x;
    }
    return 0;
}