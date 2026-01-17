mod = 10**9 + 7

def solve():
    n = int(input())
    ans = 0
    ans = (n * (n+1) * (2*n + 1) // 6) % mod
    ans += ((n-1) * n * (n + 1) // 3) % mod
    ans = (ans * 2022) % mod
    print(ans)


t = int(input())
for i in range (t):
    solve()
