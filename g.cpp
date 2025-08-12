#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

string solve(){
    ll n;
    cin >> n;

    ll a,b,c,d;
    cin >> a >> b >> c >> d;

    ll sum = 0;
    for(int i = 0; i < n; i++){
        int v;
        cin >> v;
        sum += v;
    }

    ll dx = c - a;
    ll dy = d - b;
    ld dd = sqrt((ld)dx*dx + (ld)dy*dy);

    // 1) if required straight‑line distance exceeds total step‑length → impossible
    if(dd > sum){
        return "no";
    }

    // 2) ensure dd is effectively an integer (no fractional part)
    ld rd = round(dd);
    if(fabsl(dd - rd) > 1e-9) {
        return "no";
    }

    // 3) use that exact integer distance for parity check
    ll dist = (ll)rd;
    if((sum - dist) % 2 == 0){
        return "yes";
    }
    return "no";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--){
        cout << solve() << "\n";
    }
}
