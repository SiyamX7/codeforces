#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define pb push_back
#define srt(x) sort(x.begin(), x.end())
#define rsrt(x) sort(x.rbegin(), x.rend())
#define vll vector<long long>
#define fast ios::sync_with_stdio(false); cin.tie(nullptr)
#define pop(x) __builtin_popcount(x) // x -> int

int main() {
    fast;
 	int t;
 	cin >> t;
 	while(t--){
 		ll n;
 		cin >> n;
 		
 		ll mn = 0, mx = 0;

 		if(n < 4 || n % 2 == 1){
 			cout << -1 << endl;
 		} else {
 			
 			mx = n / 4;
 			mn = (n % 6 == 0) ? n / 6 : n / 6 + 1;

 			cout << mn << " " << mx << endl;

 		}
 	}   
}