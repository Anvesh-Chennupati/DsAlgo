#include<iostream>
#include<string>

using namespace std;

// I = 1 , V = 5, X = 10, l = 50 , c = 100,D = 500 M = 1000
int main(){
    string s = "CMXCVIII";
    int slen = s.length();
    int num = 0;

    for(int i =slen-1; i>=0;i--){
        if(s[i] =='I'&& num<3){
            num+=1;
        }
        
        if(s[i] =='I'&& num>3){
            num-=1;
        }
        
        else if(s[i] =='V'){
            num+=5;
        }
        else if(s[i] == 'X' && num<30){
            num+=10;
        }
        else if(s[i] == 'X' && num>30){
            num-=10;
        }

        else if(s[i] == 'L'){
            num+=50;
        }
        else if(s[i] == 'X' && num>89){
            num-=10;
        }

        else if(s[i] == 'C' && num<400){
            num+=100;
        }
        else if(s[i] == 'C' && num>400){
            num-=100;
        }
        else if(s[i] == 'D'){
            num+=500;
        }

        else if(s[i] == 'M'){
            num+=1000;
        }

    }

    cout<<num;
}
