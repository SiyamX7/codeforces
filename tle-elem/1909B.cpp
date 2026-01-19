#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define eb emplace_back
#define bug(x) cerr << #x << " = " << x << endl
#define endl '\n'

#define rem(v,x) (v).erase(remove((v).begin(), (v).end(), (x)), (v).end())
#define leftrotate(v,k) rotate((v).begin(), (v).begin() + ((k) % (v).size()), (v).end())

#define popcountll(x) __builtin_popcountll(x)
#define lzll(x) __builtin_clzll(x)
#define tzll(x) __builtin_ctzll(x)

void fast() { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); }
template <typename T>
void print(const vector<T>& vec) { for (const auto& val : vec) cout << val << " "; cout << endl; }

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    for(int i = 1; i <= 63; i++){
        set<ll> s;
        for(int j = 0; j < n; j++){
            s.insert(a[j] % (1ll << i));
            if(s.size() > 2) break;
        }

        if(s.size() == 2){
            cout << (1ll << i) << endl;
            return;
        }
    }

}

int main() {
    fast();
    int t = 1;
    cin >> t;
    int c = 1;
    while (t--) {
        solve(); 
    }
}
