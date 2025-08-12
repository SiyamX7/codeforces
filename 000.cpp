#include <iostream>
#include <set>
#include <vector>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    // Store unique heights in a set
    set<long long> heights;
    long long current_height = 0; // Height of the starting tower

    // Read tower heights and identify starting tower height
    for (int i = 1; i <= n; i++) {
        long long h;
        cin >> h;
        heights.insert(h);
        if (i == k) {
            current_height = h; // Set starting tower height
        }
    }

    // Convert set to sorted vector of unique heights
    vector<long long> sorted_heights(heights.begin(), heights.end());

    // If already at max height or only one unique height, answer is YES
    if (sorted_heights.back() == current_height) {
        cout << "YES" << endl;
        return;
    }

    long long water_level = 1; // Initial water level
    // Try to reach each height in ascending order
    for (size_t i = 0; i < sorted_heights.size() - 1; i++) {
        long long next_height = sorted_heights[i + 1];
        long long height_diff = next_height - sorted_heights[i]; // Time needed to teleport
        long long time_available = current_height - water_level; // Time before drowning

        // Check if we can teleport to the next height in time
        if (height_diff > time_available + 1) {
            cout << "NO" << endl;
            return;
        }

        // Update position and water level after teleport
        current_height = next_height;
        water_level += height_diff;
    }

    cout << "YES" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}