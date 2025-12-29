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

    if(a == b){
    	cout << 0 << endl;
    	return;
    }

    if(a > b) swap(a, b);

    int count = 0;

	while(a < b){
		if(a * 8 <= b){
			a *= 8;
			count++;
		} else if(a * 4 <= b){
			a *= 4;
			count++;
		} else if(a * 2 <= b){
			a *= 2;
			count++;
		} else {
			break;
		}
	}

    

    if(a == b){
		cout << count << endl;
	} else {
		cout << -1 << endl;
	}
}

int main() {
    fast(); 

    int t = 1;
    cin >> t; 

    while (t--) solve();
}
    