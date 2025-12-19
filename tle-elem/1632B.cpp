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

    vector<int> v;
	for(int i = n - 1; i >= 0; i--){
		v.pb(i);
	}    

	int ind;
	for(int i = 0; i < n; i++){
		if(v[i] > 0 && (v[i] & (v[i] - 1)) == 0){
			ind = v[i];
			break;
		}
	}

	for(int i = n-1; i >= ind; i--){
		cout << i << " ";
	}

	for(int i = 0; i < ind; i++){
		cout << i << " ";
	}

	cout << endl;
}

int main() {
    fast(); 

    int t = 1;
    cin >> t; 

    while (t--) solve();
}
    