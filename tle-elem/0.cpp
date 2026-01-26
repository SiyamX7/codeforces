#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++) cin >> b[i];

        sort(a.begin(), a.end()); // ascending
        vector<long long> prefix(n+1, 0); // cumulative swords count
        for(int i = 0; i < n; i++) prefix[i+1] = prefix[i] + 1; // 1 sword per sword

        long long max_score = 0;

        // সম্ভাব্য difficulty হলো a[i] থেকে নেওয়া
        for(int i = 0; i < n; i++) {
            int x = a[i];

            // কতো swords usable (strength >= x)
            int idx = lower_bound(a.begin(), a.end(), x) - a.begin();
            int usable = n - idx;

            // এখন কতো level পার করা যাবে
            int levels_done = 0;
            int swords_left = usable;
            for(int j = 0; j < n; j++) {
                if(b[j] <= swords_left) {
                    swords_left -= b[j];
                    levels_done++;
                } else break;
            }

            max_score = max(max_score, 1LL * x * levels_done);
        }

        cout << max_score << "\n";
    }
    return 0;
}
