#include<iostream>

using namespace std;

void ModifyString(string s){
    string final = "";
    for(int i =0;i < s.length();i++){
        if(((int)s[i]>=65 && (int)s[i]<=90) || ((int)s[i]>=97 && (int)s[i]<=120)){
            s[i] = s[i];
        }
        else s[i] = ' ';
    }

    for(int i= 0;i<s.length();i++){
        if((int)s[i]>=65 && (int)s[i]<=90)
            s[i] = (char)((int)s[i]+32);
        else s[i] = s[i];
    }

    for(int i =0;i<s.length();i++){
        if((int)s[i]>=97 && (int)s[i]<=120){
         final += s[i];   
        }
        else continue;
    }
    int i =0, j = final.length()-1;
    int cond = 0;
    while(i<j){
        if(final[i]!=final[j]){
            cout<<"False";
            cond = -1;
            i++;
            j--;
            break;
        }
        else{
            i++;
            j--;
        }
    }
    if(cond == 0){
        cout<<"\n It is palindrome";
    }

}

int main(){
    string s = "race a car";
    // for(auto x:s)
    //     cout<<x;
    ModifyString(s);
    // cout<<"\n";
    // for(auto x:fs)
    //     cout<<x;
}