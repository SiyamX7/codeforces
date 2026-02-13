#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin >> a[i];

    ll cnt = 0;
	int x = 0;
    for(int i=1;i<=n;i++){
        for(int k=1;i + a[i]*k <= n; k++){
            int j = i + a[i]*k;
            if(a[j] == k) cnt++;
        }
        x++;
    }

    cout << cnt << ' ';
    cout << x << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) solve();
}
