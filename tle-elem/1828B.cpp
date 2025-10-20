#include <bits/stdc++.h>
using namespace std;

#define ll long long              
#define pb  push_back
#define eb  emplace_back                                 
#define bug(x) cerr << #x << " = " << x << endl                 
 
void fast() {ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
template <typename T>
void print(const vector<T>& vec) {for (const auto& val : vec) {cout << val << " ";}cout << endl;}

void solve(){
    int n; cin >> n;
    int g = 0;

    for(int i = 1; i <= n; i++){
    	int x; cin >> x;
    	int d = abs(i - x);
    	
    	g = gcd(d,g);
    }

    cout << g << endl;
}

int main() {
    fast(); 

    int t; 
    // t = 1;
    cin >> t; 

    while (t--) solve();
}
    