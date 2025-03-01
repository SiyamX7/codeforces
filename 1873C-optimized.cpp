#include <iostream>
#include <algorithm>  // for std::min
using namespace std;

void solve() {
    int ans = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            char c;
            cin >> c;
            if (c == 'X') {
                int cellScore = 1 + min({i, j, 9 - i, 9 - j});
                ans += cellScore;
            }
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while(tt--) {
        solve();
    }
}
