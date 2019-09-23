#include<iostream>
#include<vector>
#include<cstring>


using namespace std;

void computeLPS(int* lps,string pattern){
    int len =0;
    int i = 1;
    lps[0] = 0;
    while(i <pattern.length()){
        if(pattern[i] == pattern[len]){
            len++;
            lps[i] = len;
            i++;
        }
        else{
            if(len!=0){
                len = lps[len -1];
            }
            else{
                lps[i] = 0;
                i++;
            }
        }
    }
}

void PatternSearchKMP(string sequence, string pattern){
    if(sequence.length() < pattern.length()) cout<<"Invalid Input";
    
    //creating a lps table to track pattern occurences
    int lps[pattern.length()];
    memset(lps,0,sizeof(lps));
    computeLPS(lps,pattern);
    cout<<"\nComputed LPS ";
    for(auto x:lps) cout<<x<<" ";

    int i =0;
    int j =0;
    while(i < sequence.length()){
        if(sequence[i] == pattern[j]){
            i++;
            j++;
        }
        if(j == pattern.length()){
            cout<<"\nPattern found at Index: "<<i-j;
            j = lps[j-1];
        }

        else if (sequence[i]!= pattern[j] && i< sequence.length()){
            if(j!= 0){
                j = lps[j-1];
            }
            else{
                i++;
            }
        }
    }
}

int main(int argc,char** argv){
    string sequence = "ABABDABACDABABCABAB";
    string pattern = "ABABCABAB";
    PatternSearchKMP(sequence,pattern);
}