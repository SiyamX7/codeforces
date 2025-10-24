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
    string s; 
    cin >> s;

    s[0] = s.back();
    
    cout << s << endl;
}

int main() {
    fast(); 

    int t; 
    // t = 1;
    cin >> t; 

    while (t--) solve();
}
    