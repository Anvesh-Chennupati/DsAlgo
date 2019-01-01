// seive of eratosthenes
#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>


using namespace std;

bool isprime(int n){
    return true;
}

int main(){
    int n;
    cin>>n;
    vector<bool> prime(n, true);
            prime[0] = false, prime[1] = false;
            for (int i = 0; i < sqrt(n); ++i) {
                if (prime[i]) {
                    for (int j = i*i; j < n; j += i) {
                        prime[j] = false;
                    }    
                }    
            }
    cout<< count(prime.begin(), prime.end(), true);
}