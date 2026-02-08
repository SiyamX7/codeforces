#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;

    vector<int> mask(n,0);
    for(int i = 0; i < k ; i++){
        string s;
        cin >> s;

        for(int j = 0; j < n; j++){
            int x = s[j] - 'a';
            mask[j] |= (1 << x);
        }
    }

    vector<int> div;
    for(int i = 1; i * i <= n; i++){
        if(n % i == 0) {
            div.push_back(i);
            if(i * i != n) div.push_back(n/i);
        }
    }

    sort(div.begin(), div.end());
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}   