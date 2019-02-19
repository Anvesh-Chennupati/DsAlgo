#include<bits/stdc++.h>

// 84114117116104326510811997121115328710511011532

// A-Z 65 - 90
// a-z 97 - 122
// space 32

using namespace std;

string decode(string encode){
    string ans = "";
    if(encode.empty()){
        return ans;
    }
    string proc = encode;
    reverse(proc.begin(),proc.end());
    vector<int> conv;
    // cout<<"\n"<<encode;
    cout<<"\n"<<proc;
    for(int i=0; i < proc.length();i++){
        conv.push_back((int)(proc[i] - 48));
    }
    cout<<endl;
    // for(auto x:conv) cout<<x;

    for(int i =0; i<conv.size() && i+1 < conv.size() && i+2 <conv.size(); ){
        int temp1 = ((conv[i] * 10) + conv[i+1]);
        int temp2 = ((conv[i] * 100) + (conv[i+1]* 10) + conv[i+2]);
        if(temp1 <=99 && temp1 >= 32){
           if(temp1  == 32){
               ans += " ";
               i+=2;
           }
           else if(temp1 >= 65 && temp1 <=90){
               ans+= (char)temp1;
               i+=2;
           }
           else if(temp1 >=97 && temp1 <=99){
               ans+=(char)temp1;
               i+=2;
           }
           else return NULL; 
        }

        else if(temp2 >=100 && temp2<= 122){
            ans+= (char)temp2;
            i+=3;
        }
        else return NULL;
    }
    return ans;
}

int main(){
    string encode = "1219950180111108236115111016623101401611235115012312161151110101111127";
    cout<<"\n"<<decode(encode);

}