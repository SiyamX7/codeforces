#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> a(n);
    for(auto &x : a) cin >> x;

    long long ans = LLONG_MIN;

    for(int i = 0; i < n; i++) {
        long long sum = 0;
        for(int j = i; j < n; j++) {
            sum += a[j];
            ans = max(ans, sum);
        }
    }

    cout << ans << '\n';
}
