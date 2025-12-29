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
    int n, k;
    cin >> n >> k;

    if(k % 2 == 0){
    	for(int i = 1; i <= n; i++){
    		if(i == n-1){
    			cout << n << " ";
    		} else {
    			cout << n-1 << " ";
    		}
    	}
    } else {
    	for(int i = 1; i <= n; i++){
    		if(i == n){
    			cout << n - 1 << " ";
    		} else {
    			cout << n << " ";
    		}
    	}
    }

    cout << endl;
}

int main() {
    fast(); 

    int t = 1;
    cin >> t; 

    while (t--) solve();
}
    