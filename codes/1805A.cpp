#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define pb push_back
#define srt(x) sort(x.begin(), x.end())
#define vll vector<long long>
#define fast ios::sync_with_stdio(false); cin.tie(nullptr);
#define pop(x) __builtin_popcount(x) // x -> int
using namespace std;

int solve(){
	int n;
	cin >> n;

	int ans = 0;

	for(int _ = 0; _ < n; _++){
		int x;
		cin >> x; 
		ans ^= x;
	}

	if(n % 2 == 1) {
		return ans;
	}else if (ans == 0) {
		return 0;
	} else return -1;
}

int main() {
    fast;
 	int t;
 	cin >> t;
 	while(t--){
 		cout << solve() << endl;
 	}   
}