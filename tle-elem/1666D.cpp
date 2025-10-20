#include <algorithm>
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
    string s, t;
    cin >> s >> t;
    map<char,vector<int>> pos;

    for(int i = 0; i < s.size(); i++){
    	pos[s[i]].pb(i);
    }

    vector<int> v;

    for(int i = t.size()-1 ; i >= 0 ; i--){
    	if(pos[t[i]].empty()){
    		cout << "NO" << endl;
    		return;
    	}

    	v.pb(pos[t[i]].back());
    	pos[t[i]].pop_back();
    }

    // reverse(v.begin(), v.end());

    if(is_sorted(v.rbegin(), v.rend())){
    	cout << "YES" << endl;
    } else {
    	cout << "NO" << endl;
    }
}

int main() {
    fast(); 

    int t; 
    // t = 1;
    cin >> t; 

    while (t--) solve();
}
    