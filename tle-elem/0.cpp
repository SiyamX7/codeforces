#include <bits/stdc++.h>
using namespace std;

#define int long long
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
    int n, m, k;
    cin >> n >> m >> k;
    set<int> r, s;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        r.insert(x);
    }

    for(int i = 0; i < m; i++){
        int x; cin >> x;
        s.insert(x);
    }
    
    string ss;
    cin >> ss;

    int count = 0;

    for(int i = 0; i < k; i++){
        if(ss[i] == 'L'){
            count--;
        } else {
            count++;
        }

        vector<int> rem;

        for(int i : s){
            int p = i - count;

            if(r.count(p)) rem.pb(p);
        }

        for(int i : rem){
            r.erase(i);
        }

        cout << r.size() << " ";
    }

    cout << endl;
}

signed main() {
    fast();
    int t = 1;
    cin >> t;
    while (t--) solve();
}