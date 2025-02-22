#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
using namespace std;                   

int main() {
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;

        vi v(n);
        for(int &i : v) cin >> i;

        int mx = v[0];
        mx = max(mx, (k - v[n-1]) * 2);

        for(int i = 1; i < n; i++){
            mx = max(mx, v[i] - v[i-1]);
        }
        cout << mx << endl;
    }
}