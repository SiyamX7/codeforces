#include <bits/stdc++.h>
using namespace std;

#define ll  long long              
#define pb  push_back
#define eb  emplace_back                                 
#define bug(x) cerr << #x << " = " << x << endl                 
 
void fast() {ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
template <typename T>
void print(const vector<T>& vec) {for (const auto& val : vec) {cout << val << " ";}cout << endl;}

vector<bool> isPrime;
vector<int> primes;

void solve(){
	int d;
	cin >> d;
	int ans = 1;

	int x = d+1;

	int p1 = *lower_bound(primes.begin(), primes.end(), x);

	x = p1 + d;

	int p2 = *lower_bound(primes.begin(), primes.end(), x);

	ans = p1 * p2;

	cout << ans << endl;
}

int main() {
    fast();

    int t = 1;
    cin >> t; 

    isPrime.assign(1e5+1,true);
    isPrime[0] = isPrime[1] = false;

    for(int i = 2; i*i <= 1e5; i++){
    	if(isPrime[i]){
    		for(int j = i*i; j <= 1e5; j += i){
    			isPrime[j] = false;
    		}
    	}
    }

    for(int i = 2; i <= 1e5; i++){
    	if(isPrime[i])
    		primes.pb(i);
    }

    // print(primes);
    while (t--) solve();
}