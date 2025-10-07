#include <bits/stdc++.h>
using namespace std;

vector<int> a;
int n;
vector<vector<int>> dp;
vector<vector<int>> parent;

int lis(int i, int prev) {
    if (i == n) return 0;

    if (dp[i][prev + 1] != -1) return dp[i][prev + 1];

    int take = 0, skip = 0;

    // Skip current element
    skip = lis(i + 1, prev);

    // Take current element if it’s increasing
    if (prev == -1 || a[i] > a[prev]) {
        take = 1 + lis(i + 1, i);
    }

    // Record parent for reconstruction
    if (take > skip)
        parent[i][prev + 1] = i + 1; // means we took a[i]
    else
        parent[i][prev + 1] = -1;    // we skipped a[i]

    return dp[i][prev + 1] = max(take, skip);
}

// Helper to rebuild LIS
void printLIS(int i, int prev) {
    if (i == n) return;

    int skip = lis(i + 1, prev);
    int take = 0;
    if (prev == -1 || a[i] > a[prev])
        take = 1 + lis(i + 1, i);

    if (take >= skip) {
        cout << a[i] << " ";
        printLIS(i + 1, i);
    } else {
        printLIS(i + 1, prev);
    }
}

int main() {
    a = {10, 9, 2, 5, 3, 7, 101, 18};
    n = a.size();

    dp.assign(n, vector<int>(n + 1, -1));
    parent.assign(n, vector<int>(n + 1, -1));

    cout << "LIS length = " << lis(0, -1) << "\n";
    cout << "LIS sequence: ";
    printLIS(0, -1);
    cout << "\n";
}
