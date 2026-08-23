#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;

// S(N) = sum_{n=1}^{N} (bit-length of n), computed as exact integer (fits easily in long long)
long long S(long long N) {
    if (N <= 0) return 0;
    long long total = 0;
    long long lo = 1; // 2^k
    int k = 0;
    while (lo <= N) {
        long long hi = lo * 2 - 1; // 2^(k+1) - 1
        long long upper = min(hi, N);
        long long count = upper - lo + 1;
        total += count * (long long)(k + 1);
        lo *= 2;
        k++;
        if (lo > (long long)2e9) break; // safety, won't actually trigger for N <= 1e9
    }
    return total;
}

int main(){
    int q;
    scanf("%d", &q);
    while (q--) {
        long long L, R;
        scanf("%lld %lld", &L, &R);
        long long ans = S(R) - S(L - 1); // exact integer arithmetic, always >= 0
        ans %= MOD;
        printf("%lld\n", ans);
    }
    return 0;
}