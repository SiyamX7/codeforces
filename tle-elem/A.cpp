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
    vector<string> v(n);
    for(int i = 0; i < n; i++){
    	cin >> v[i];
    }

    string s = v[0];

    for(int i = 1; i < n; i++){
    	string x = v[i] + s;
    	string y = s + v[i];

    	if(x < y){
    		s = x;
    	} else {
    		s = y;
    	}
    }
    //print(v);
    cout << s << endl;
}

int main() {
    fast(); 

    int t = 1;
    cin >> t; 

    while (t--) solve();
}
    