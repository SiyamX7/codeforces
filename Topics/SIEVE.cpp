#include <bits/stdc++.h>
using namespace std;

vector<bool> isPrime;
vector<int> primes;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    

   	int n;
    cin >> n;
    isPrime.assign(n+1, true);

    isPrime[0] = isPrime[1] = false;

    for(int i = 2; i * i <= n; i++){
    	if(isPrime[i]){
    		for(int j = i * i; j <= n; j += i){
    			isPrime[j] = false; 
    		}
    	}
    }

    for(int i = 0; i <= n; i++){
    	if(isPrime[i]) {
    		primes.push_back(i);
    	}
    }

    for(auto x : primes) cout << x << " ";

}   