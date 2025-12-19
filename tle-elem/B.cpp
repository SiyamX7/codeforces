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
    int l, a, b;
    cin >> l >> a >> b;
    set<int> s;

    if(b == 1){
    	cout << l - 1 << endl;
    	return;
    }

    int i = 0;

    while(1){
    	int val = (a + i*b) % l;
    	i++;
    	if(s.count(val)){
    		break;
    	} else {
    		s.insert(val);
    	}
    }

    // for(auto x : s){
    // 	cout << x << " ";
    // }

    cout << *s.rbegin() << endl;
}

int main() {
    fast(); 

    int t = 1;
    cin >> t; 

    while (t--) solve();
}
    