#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
	ll n, k, x;
	cin >> n >> k >> x;

	ll r = n - k;

	ll nsum = n * (n + 1) / 2;
	ll ksum = k * (k + 1) / 2;
	ll rsum = r * (r + 1) / 2;

	ll mxsum = nsum - rsum;

	if(x >= ksum && x <= mxsum){
		cout << "yes" << endl;
	} else {
		cout << "no" << endl;
	}
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
	int t;
	cin >> t;
	while (t--) solve();    
}   