#include <bits/stdc++.h>
#include <climits>
using namespace std;

#define ll  long long              
#define pb  push_back
#define eb  emplace_back                                 
#define bug(x) cerr << #x << " = " << x << endl                 
 
void fast() {ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
template <typename T>
void print(const vector<T>& vec) {for (const auto& val : vec) {cout << val << " ";}cout << endl;}

void solve(){
    int n, m;
    cin >> n >> m;
    int v[n][m];

    int mn = INT_MAX;
    int neg = 0;

    for(int i = 0; i < n; i++){
    	for(int j = 0; j < m; j++){
    		cin >> v[i][j];

    		if(v[i][j] < 0) neg++;
    		mn = min(mn, abs(v[i][j]));
    	}
    }
    int sum = 0;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			sum += abs(v[i][j]);
		}
	}

   	if(neg % 2 == 0){
   		cout << sum << endl;
   	} else {
   		cout << sum - mn * 2 << endl;
   	}
}

int main() {
    fast(); 

    int t = 1;
    cin >> t; 

    while (t--) solve();
}
    