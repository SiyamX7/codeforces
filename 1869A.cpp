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

void solve(){
	int n;
	cin >> n;
	
	vi v(n);
	for(int &i : v) cin >> i;

	if(n % 2 == 0){
		cout << 2 << endl;
		cout << 1 << " " << n << endl;
		cout << 1 << " " << n << endl;
	} else {
		cout << 4 << endl;
		cout << 1 << " " << n << endl;
		cout << 1 << " " << n - 1 << endl;
		cout << n - 1 << " " << n << endl;
		cout << n - 1 << " " << n << endl;
	}
}

int main() {
    fast;
 	int t;
 	cin >> t;
 	while(t--){
 		solve();
 	}   
}