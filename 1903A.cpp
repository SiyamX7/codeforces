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

        bool flag = is_sorted(v.begin(), v.end());

        if(k == 1){
            if(flag) cout << "YES" << endl;
            else cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }
}