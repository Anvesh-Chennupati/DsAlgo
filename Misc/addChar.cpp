#include<iostream>

using namespace std;

void ModifyS(string s, int k){
    string temp ="";
    for(int i =0;i<s.length();i++){
        if((int)s[i]<=122 && (int)s[i] >= 97){
            s[i] = (char)((int)s[i] -32);
        }
    }

    for( int i =0;i<s.length();i++){
        if(s[i]!='-'){
            temp += s[i];
        }
    }

    s = temp;
    temp = "";
    if(k> s.length())
    {
        cout<<" Invalid";
    }

    else{

        if(s.length()%k==1){
            temp+=s[0];
            temp+="-";

            for(int i =1;i <s.length();i++){
            if((i-1)!=0 &&(i-1) % k ==0){
            temp+="-";
        }

        temp+=s[i];

    }
    // cout<<temp;
        }
        else{
            for(int i =0;i <s.length();i++){
            if((i) % k ==0){
            temp+="-";
        }

        temp+=s[i];
    }
    s = temp;
    temp = "";
    for(int i=1;i<s.length();i++)
{
    temp+=s[i];
}
    }
    }

cout<<"\n"<<temp;
}

int main(){
    string s1 = "2-4a0r7-4k";
    int k = 4;
    ModifyS(s1,k);
    return 0;
}