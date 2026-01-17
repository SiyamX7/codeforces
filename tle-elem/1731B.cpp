#include <bits/stdc++.h>
using namespace std;

using i128 = __int128;

void print128(i128 x) {
    if(x == 0){
        cout << 0;
        return;
    }

    string s = "";
    bool neg = false;
    if(x < 0) {
        neg = true;
        x = -x;
    }

    while(x > 0) {
        s += '0' + (x % 10);
        x /= 10;
    }

    if(neg) cout << '-';
    reverse(s.begin(), s.end());
    cout << s << endl;
}

const int mod = 1000000007;

void solve(){
    int n;
    cin >> n; 

    i128 ans = n * (n+1) * (2 * n + 1) / 6 % mod;
    ans += (n-1) * n * (n+1) / 3 % mod;

    ans = (ans * 2022) % mod;
    print128(ans);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--) solve();
}   