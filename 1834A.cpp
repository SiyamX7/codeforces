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
 	int t;
 	cin >> t;
 	while (t--) {
 		int n; 
 		cin >> n;
 		
 		int neg = 0;
 		for(int i = 0; i < n; i++){
 			int x; cin >> x;
 			if(x == -1) neg++;
 		}   

 		int res = 0;

 		while (neg > n/2 || neg % 2 == 1) {
 			neg--; 
 			res++;
 		}
 		cout << res << endl;
 	}   
}