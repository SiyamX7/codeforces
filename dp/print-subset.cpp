#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, target;
    cin >> n >> target;

    vector<int> arr(n);
    for(int &x : arr) cin >> x;

    // DP table
    vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));

    // sum = 0 always possible with empty subset
    for(int i = 0; i <= n; i++) dp[i][0] = true;

    // build dp
    for(int i = 1; i <= n; i++) {
        for(int s = 0; s <= target; s++) {

            bool notTake = dp[i-1][s];
            bool take = false;

            if(s >= arr[i-1])
                take = dp[i-1][s - arr[i-1]];

            dp[i][s] = take || notTake;
        }
    }

    if(dp[n][target] == false){
        cout << "No subset found\n";
        return 0;
    }

    // Backtrack to find subset
    vector<int> subset;
    int s = target;

    for(int i = n; i >= 1; i--) {
        if(dp[i-1][s] == true) {
            // this element was NOT taken
            continue;
        } else {
            // this element WAS taken
            subset.push_back(arr[i-1]);
            s -= arr[i-1];
        }
    }

    reverse(subset.begin(), subset.end());

    cout << "Subset: ";
    for(int x : subset) cout << x << " ";
    cout << "\n";
}
