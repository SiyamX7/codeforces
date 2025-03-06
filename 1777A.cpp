#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define pb push_back
#define srt(x) sort(x.begin(), x.end())
#define vll vector<long long>
#define fast ios::sync_with_stdio(false); cin.tie(nullptr);

using namespace std;                   

int main() {
    fast;
 	ll t;
 	cin >> t;
 	while(t--){
 		ll n;
 		cin >> n;
 		vll v(n);
 		for(int i = 0; i < n; i++){
 			ll x;
 			cin >> x;
 			if(x & 1) v[i] = 1; else v[i] = 0;
 		}

 		// for(ll x : v) cout << x << " ";
 		// cout << endl;

 		ll count = 0;
 		for(ll i = 0; i < n - 1; i++){
 			if((v[i] ^ v[i+1]) == 0) count++;
 		}

 		cout << count << endl;
 	}   
}