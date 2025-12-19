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
    string s;
    cin >> s;

    int b = 0;
    for(int i = 0; i < k; i++){
    	if(s[i] == 'B') b++;
    }

    bug(b);

    int l = 0, r = k;

    int ans = k - b;

    while (r < n) {
    	if(s[r] == 'B') b++;
    	if(s[l] == 'B') b--;

    	ans = min(ans, k - b);
    	r++; l++;
    }

    cout << ans << endl;
}

int main() {
    fast(); 

    int t = 1;
    cin >> t; 

    while (t--) solve();
}