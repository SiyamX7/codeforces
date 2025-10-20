#include <bits/stdc++.h>
#include <iterator>
using namespace std;

#define ll long long              
#define pb  push_back
#define eb  emplace_back                                 
#define bug(x) cerr << #x << " = " << x << endl                 
 
void fast() {ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
template <typename T>
void print(const vector<T>& vec) {for (const auto& val : vec) {cout << val << " ";}cout << endl;}

void solve(){
    int n, k;
    cin >> n >> k ;

    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    sort(begin(v),end(v));

	int count = 1, mx = 1;

	for(int i = 1; i < v.size(); i++){
		if(v[i] - v[i-1] <= k){
			count++;
			mx = max(mx, count);
		} else {
			count = 1;
		}
	}
	
	bug(mx);
	cout << n - mx << endl;
}

int main() {
    fast(); 

    int t; 
    // t = 1;
    cin >> t; 

    while (t--) solve();
}
    