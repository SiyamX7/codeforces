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
    ll a, b;
    cin >> a >> b;

    if(a % 2 == 1 && b % 2 == 1){
    	cout << a*b + 1 << endl;
    	return;
    }

    if(a % 2 == 0 && b % 2 == 1){
    	cout << -1 << endl;
    	return;
    }

    if(a % 2 == 1 && b % 2 == 0){
    	if(b % 4 == 0){
    		cout << a * b / 2 + 2 << endl;
    		return;
    	} else {
    		cout << -1 << endl;
    		return;
    	}
    }

    cout << a * b / 2 + 2 << endl;

}

int main() {
    fast(); 

    int t = 1;
    cin >> t; 

    while (t--) solve();
}
    