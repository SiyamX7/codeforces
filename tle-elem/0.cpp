#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        long long n, k;
        cin >> n >> k;

        k %= 2;   // only parity matters

        vector<long long> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

        vector<long long> prefixSum(n + 1);
        prefixSum[0] = 0;

        for (int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + a[i];
        }

        vector<long long> minPrefix(n + 1);
        vector<long long> maxSuffix(n + 1);

        for (int i = 0; i <= n; i++) {
            minPrefix[i] = prefixSum[i];
            maxSuffix[i] = prefixSum[i];
        }

        for(int i = 0; i <= n; i++){
            cout << prefixSum[i] << " ";
        }
        cout << endl;

        // compute minimum prefix
        for (int i = 1; i <= n; i++) {
            minPrefix[i] = min(minPrefix[i], minPrefix[i - 1]);
            cout << minPrefix[i] << " ";
        }
        cout << endl;

        // compute maximum suffix
        for (int i = n - 1; i >= 0; i--) {
            maxSuffix[i] = max(maxSuffix[i], maxSuffix[i + 1]);
            cout << maxSuffix[i] << " ";
        }
        cout << endl;

        long long ans = -INF;

        for (int i = 0; i < n; i++) {
            long long bestSubarrayThroughI =
                maxSuffix[i + 1] - minPrefix[i];

            long long candidate =
                bestSubarrayThroughI + b[i] * k;

            ans = max(ans, candidate);
        }

        cout << "\n";
    }
}