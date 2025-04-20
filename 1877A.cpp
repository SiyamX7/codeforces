#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define vb vector<bool>
#define fast ios::sync_with_stdio(0); cin.tie(0);

using namespace std;                   

int main() {
    fast;
 	int t;
 	cin >> t;
 	while(t--){
 		int n;
 		cin >> n;
 		ll sum = 0;
 		for(int i = 0; i < n -1 ; i++){
 			ll x;
 			cin >> x;
 			sum += x;
 		}

 		cout << -sum << endl;
 	}   
}