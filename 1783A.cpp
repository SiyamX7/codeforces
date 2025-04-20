#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
	ll t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		vector<ll> v(n);
		for(ll &i : v) cin >> i;

		sort(v.rbegin(), v.rend());
		bool flag = false;

		if(v[0] == v[1]){
			if(v[1] == v[n-1]){
				flag = true;
			} else {
				swap(v[1],v[n-1]);
			}
		}

		if(flag){
			cout << "NO" << endl;
		} else {
			cout << "YES" << endl;
			for(ll i : v) cout << i << " ";
			cout << endl;			
		}
	}
}