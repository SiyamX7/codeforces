#include <bits/stdc++.h>
using namespace std;

vector<int> primes;
vector<int> spf;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n; 
    cin >> n;

    spf.assign(n+1, 0);

    for(int i = 2; i <= n; i++){
    	if(spf[i] == 0){
    		primes.push_back(i);
    		spf[i] = i;
    	}

    	for(int p : primes){
    		if(p > spf[p] || 1LL * p * i > n) break;

    		spf[p * i] = p;
    	}
    }

    for(int x : primes) cout << x << " ";
}   