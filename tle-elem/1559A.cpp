#include <bits/stdc++.h>
using namespace std;

#define ll  long long              
#define pb  push_back
#define eb  emplace_back                                 
#define bug(x) cerr << #x << " = " << x << endl                 

void fast() { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); }

 // rotation: apply machines in s one-by-one until either finish s
 // or x becomes 0. return {new_x, steps_used_in_this_rotation}.
pair<ll,ll> rotation(ll x, const string &s){
    ll used = 0;
    for (int i = 0; i < (int)s.size(); ++i) {
        if (x == 0) break;
        if (s[i] == 'A') x -= 1;
        else x /= 2;
        used++;
    }
    return {x, used};
}

void solve(){
    ll n, q;
    cin >> n >> q;
    string s;
    cin >> s;

    unordered_map<ll, ll> mp; // mp[x] = steps needed to reduce x to 0 (cached)

    while (q--) {
        ll x;
        cin >> x;

        if (mp.count(x)) {
            cout << mp[x] << '\n';
            continue;
        }

        ll orig = x;
        ll count = 0;

        // simulate using full-rotation chunks but count exact steps used
        while (x > 0) {
            if (mp.count(x)) {
                count += mp[x];
                x = 0;
                break;
            }

            auto pr = rotation(x, s);
            ll nx = pr.first;
            ll used = pr.second;

            count += used;

            if (nx == x) {
                // no progress after a rotation (edge case) -> avoid infinite loop
                // In practice this rarely happens for x>0, but keep safe: break.
                break;
            }
            x = nx;
        }

        // store result for orig x
        mp[orig] = count;
        cout << count << '\n';
    }
}

int main() {
    fast(); 

    int t = 1;
    cin >> t; 
    while (t--) solve();
}
