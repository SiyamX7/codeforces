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
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    if(n == 1){
        cout << 0 << endl;
        return;
    }

    vector<int> dist;   
    int mn = INT_MAX;
    for(int i = 1; i < n; i++){
        int x = v[i] - v[i-1];
        dist.pb(x);
        mn = min(x, mn);
    }

    int count = 0;
    for(int i = 0; i < dist.size(); i++){
        if(dist[i] == mn){
            count++;
        } 
        else if(i > 0 && i+1 < dist.size() && dist[i] + dist[i-1] == dist[i+1]){
            count++;
        }
    }

    cout << count + 1 << endl;
}

int main() {
    fast(); 

    int t;
    cin >> t; 

    while (t--) solve();
}
