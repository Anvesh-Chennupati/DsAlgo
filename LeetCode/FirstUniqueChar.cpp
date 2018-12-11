#include<iostream>
#include<unordered_map>

using namespace std;

int firstUniqueChar1(string s){
    int n = s.length();
    if(n ==1){
        return 0;
    }
        int con = 0;
        for(int i =0;i<n;i++){
            con = 0;
            for(int j = i+1;j<n;j++){
                if(s[i]!= s[j]){
                   continue; 
                }
                else{
                    con =1;
                }
            }

            if(con ==0){
                return i;
            }
        
            
        }
        return -1;
    }




int Hashfirstuni(string s){
    if(s.length()==1)
        return 0;
    
    unordered_map<char,int> m1;
    int n = s.length();

    for(int i = 0;i<n;i++){
        if(m1.find(s[i])!=m1.end()){
            m1[s[i]]++;
        }
        else{
            m1[s[i]] = 0;
        }
    }

    for(int i =0;i<n;i++){
        if(m1[s[i]]==0)
            return i;
        }
       return -1; 
    }
    


int main(){
    string s = "a";
    int pos;
    // pos = firstUniqueChar1(s);
    pos = Hashfirstuni(s);
    cout<<"\nposition :"<<pos;
    // cout<<"\n char: "<<s[pos];
}