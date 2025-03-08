#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define pb push_back
#define srt(x) sort(x.begin(), x.end())
#define vll vector<long long>
#define fast ios::sync_with_stdio(false); cin.tie(nullptr);
#define pop(x) __builtin_popcount(x) // x -> int
using namespace std;
int main() {
    fast;
 	int t;
 	cin >> t;
 	while(t--){
 		int n;
 		cin >> n;
 		vi v(n);
 		

 		for(int &i : v){
 			cin >> i;
 		}
 		int mngcd = INT_MAX;

 		for(int i = 0; i < n; i++){
 			for(int j = 0; j < n; j++){
 				if(i != j){
 					int gcd = __gcd(v[i], v[j]);
 					mngcd = min(mngcd,gcd);
 				}
 			}
 		}

 		if(mngcd < 3){
 			cout << "yes" << endl;
 		} else {
 			cout << "no" << endl;
 		}
 		// cout << mngcd << endl;
 	}   
}