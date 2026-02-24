#include <bits/stdc++.h>
using namespace std;
#define int long long

int n;
vector<int> primes, spf;

void LinearSIEVE(){
	for(int i = 2; i <= n; i++){
		if(spf[i] == 0){
			primes.push_back(i);
			spf[i] = i;
		}

		for(int p : primes){
			if(p > spf[i] || 1LL * p * i > n) break;

			spf[p*i] = p;
		}
    }
}

vector<int> primeFactors(int x){
	vector<int> v;

	while(x > 1){
		v.push_back(spf[x]);
		x /= spf[x];
	}

	return v;
}


int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int x;
    cin >> x;
    vector<int> a(x);
    for(int i = 0; i < x; i++) cin >> a[i];

    for(int i = 0; i < x ; i++){
    	n = a[i];
    	primes.clear();
    	spf.clear();
	    spf.assign(n+1,0);
	    LinearSIEVE();
	    vector<int> factors = primeFactors(n);

	    cout << "Number: " << n << " : ";
	    for(int v : factors) cout << v << " ";
	    cout << endl;
    }

    // spf.assign(n+1,0);
    // LinearSIEVE();

    // vector<int> factors = primeFactors(n);

    // for(int x : factors) cout << x << " ";
}   