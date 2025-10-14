#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define vb vector<bool>
#define fast ios::sync_with_stdio(0); cin.tie(0);

using namespace std;                   

int main() {
    fast;
    ll t; cin >> t;
    while (t--) {
    	ll n, k;
    	cin >> n >> k;
    	if(n % k == 0){
    		cout << 2 << endl;
    		cout << n - 1 << " " << 1 << endl;
    	} else {
    		cout << 1 << endl << n << endl;
    	}
    }
}