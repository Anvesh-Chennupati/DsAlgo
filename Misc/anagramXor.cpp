#include<iostream>
#include<string>

using namespace std;

bool isAnagram(string s1, string s2){
    if(s1.length()!=s2.length()) return false;
    unsigned int check = 0;
    for(unsigned int x=0; x <s1.length(); x++){
        check += -1 * (int)s1[x];
        check += (int)s2[x];
    }
    if(!check) return true;
    return false;
}

int main(int argc, char** argv){
    string s1 = "Dormitory";
    string s2 = "Dirtyroom";
    isAnagram(s1,s2) ? cout<<"Yes" :cout<<"No";
    return 0;
}