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

    vector<bool> used(1<<n, false);
    int mask = (1 << n) - 1;

    int count = 0;
    while(count < (1 << n)){

        vector<int> t;

        for(int i = 0; i < (1<<n); i++){
            if((i & mask) == mask && !used[i]){
                t.pb(i);
                used[i] = 1;
            }
        }

        mask >>= 1;
        sort(t.begin(), t.end());
        for(int i : t) cout << i << " ";
        count += t.size();
    }

}

int main() {
    fast(); 

    int t = 1;
    cin >> t; 

    while (t--) solve();
}
    