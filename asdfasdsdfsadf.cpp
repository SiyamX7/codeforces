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
	string s;
	cin >> s;
    ll n = s.size();

    int count = 1;

    for(int i = 0; i < n-1; i++){
    	int r = i;
    	while (s[i] == s[r]) r++;

    	count = max( count, r - i);
    }
    cout << count << endl;

}

int main() {
    fast(); 

    int t = 1;
    // cin >> t; 

    while (t--) solve();
}
    