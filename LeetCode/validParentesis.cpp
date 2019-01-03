#include<iostream>
#include<stack>
#include<unordered_map>

using namespace std;

int main(){
    unordered_map<char,char> map = {{'{','}'},{'(',')'},{'[',']'}};
    string s = "{}{}[]{([])}";
    stack<char> s1;
    int i;

    for(i =0;i<s.length();i++){
        if(s[i] == '{' || s[i] == '[' || s[i] == '('){
            s1.push(s[i]);
        }
        else{
            if(!s1.empty()){
                char x = s1.top();
                // cout<<s[i] <<"-"<<map[x]<<endl;
                if(map[x] == s[i]){
                    s1.pop();
                }
                
                else {
                    cout<<s[i];
                    cout<<"\n1 Not valid";
                    break;
                }
            }
            else{
                cout<<"\n2 Not valid";break;
            }
        }
    }
    // cout<<endl;
    // cout<<"i val"<<i<< "string length" << s.length();

    if(i == s.length() && s1.empty() == true){
        cout<<"\nValid Parenthesis";
    }
    else{
        cout<<"\nInvalid Parenthesis";
    }

    return 0;
}