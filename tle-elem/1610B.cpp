#include <bits/stdc++.h>
using namespace std;

#define ll  long long              
#define pb  push_back
#define eb  emplace_back                                 
#define bug(x) cerr << #x << " = " << x << endl                 
 
void fast() {ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
template <typename T>
void print(const vector<T>& vec) {for (const auto& val : vec) {cout << val << " ";}cout << endl;}

void solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    int i = 0;
	
	while(i < n && v[i] == v[n-1-i]) i++;

	if(i == n){
		cout << "YES" << endl;
		return;
	}

	int prob[2] = {v[i] , v[n-1-i]};

	for(int k = 0; k < 2; k++){
		vector<int> a;

		for(int x : v){
			if(x != prob[k]){
				a.pb(x);
			}
		}


		auto b = a;

		reverse(b.begin(), b.end());

		if(a == b) {
			cout << "YES" << endl;
			return;
		}
	}

	cout << "NO" << endl;
}

int main() {
    fast(); 

    int t = 1;
    cin >> t; 

    while (t--) solve();
}
    