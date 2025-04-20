#include <bits/stdc++.h>
#include <climits>
#define ll long long
#define vi vector<int>
#define pb push_back
#define srt(x) sort(x.begin(), x.end())
#define vll vector<long long>
#define fast ios::sync_with_stdio(false); cin.tie(nullptr);
int MOD = 1e9 + 7;
using namespace std;                   

int main() {
    fast;
 	ll t;
 	cin >> t;
 	while(t--){
 		ll n;
 		cin >> n;
 		vll v(n), index;

 		for(int i = 0; i < n; i++){
 			cin >> v[i];
 			if(v[i] == 2){
 				index.pb(i);
 			}
 		}

 		if(index.size() == 0) {
 			cout << 1 << endl;
 		} else if(index.size() % 2 == 1){
 			cout << -1 << endl;
 		} else {
 			cout << index[index.size() / 2 - 1] + 1 << endl;
 		}
 	}   
}