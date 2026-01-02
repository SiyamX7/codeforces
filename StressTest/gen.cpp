#include <bits/stdc++.h>
using namespace std;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

long long rand_ll(long long l, long long r) {
    uniform_int_distribution<long long> dist(l, r);
    return dist(rng);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = rand_ll(1, 20);       // array size 1..20
    cout << n << "\n";

    for (int i = 0; i < n; i++) {
        cout << rand_ll(-100, 100) << " ";   // include negative numbers
    }
    cout << "\n";
}
