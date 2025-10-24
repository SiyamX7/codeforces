#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

#define ll  long long              
#define pb  push_back
#define eb  emplace_back                                 
#define bug(x) cerr << #x << " = " << x << endl                 
 
void fast() {ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
template <typename T>
void print(const vector<T>& vec) {for (const auto& val : vec) {cout << val << " ";}cout << endl;}

void solve(){
    int n; cin >> n;
    unordered_map<int,int> f;
    int mx = 1;
    for(int i = 0; i < n; i++){
    	int x;
    	cin >> x;
    	f[x]++;
    	mx = max(mx, f[x]);
    }

    if(mx == n){
    	cout << 0 << endl;
    	return;
    }

    int count = 0;
    int rem = n - mx;

    while (rem > 0) {
        count++;
        if(mx * 2 <= n){
            count += mx;
            mx = mx * 2;
            rem = n - mx;
        } else {
            count += (n - mx);
            rem = 0;
        }
    }    

    cout << count << endl;
}

int main() {
    fast(); 

    int t = 1;
    cin >> t; 

    while (t--) solve();
}
    