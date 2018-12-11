#include<iostream>
#include<algorithm>

using namespace std;

bool ValidAnagram(string s,string t){
    bool con = true;
        if(s.length() == t.length()){
            sort(s.begin(), s.end());
            sort(t.begin(), t.end());
            
            for(int i =0;i<s.length();i++){
                if(s[i]==t[i]){
                    continue;
                }
                else con = false;
            }
            return con;
        }
        else{
            return false;
        }
}

int main(){
    string s = "anvesh";
    string t = "hbvsna";
    cout<<ValidAnagram(s,t);
}