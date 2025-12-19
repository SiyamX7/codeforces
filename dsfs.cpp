#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        // Try x from 2 to 100 (usually the answer is small)
        for (long long x = 2; x <= 100; ++x) {
            for (long long ai : a) {
                if (__gcd(ai, x) == 1) {
                    cout << x << endl;
                    goto next_test_case;
                }
            }
        }
        cout << -1 << endl;
        next_test_case:;
    }
    return 0;
}