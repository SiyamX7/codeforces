#include <algorithm>
#include <bits/stdc++.h>
#include <functional>
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
    vector<pair<ll,ll>> a(n), b(n), c(n);
    for(int i = 0; i < n; i++){
    	ll x; 
    	cin >> x;
    	a[i] = {x,i};
    }

    for(int i = 0; i < n; i++){
    	ll x; 
    	cin >> x;
    	b[i] = {x,i};
    }

    for(int i = 0; i < n; i++){
    	ll x; 
    	cin >> x;
    	c[i] = {x,i};
    }

    sort(a.begin(), a.end(), greater<>());
    sort(b.begin(), b.end(), greater<>());
    sort(c.begin(), c.end(), greater<>());

    ll ans = 0;

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 3; k++){
                ll x = a[i].second;
                ll y = b[j].second;
                ll z = c[k].second;

                if(x != y && y != z && z != x){
                    ans = max(ans, a[i].first + b[j].first + c[k].first);
                }
            }
        }
    }

    cout << ans << endl;
}

int main() {
    fast();
    int t = 1;
    cin >> t;
    while (t--) solve();
}
    