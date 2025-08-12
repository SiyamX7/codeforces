#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    int count = 0;

    for(int i = 0; i < n; i++){
        if(v[i] == 0){
            int sum = 0;
            for(int j = i; j < i + k; j++){
                sum += v[j];
            }

            if(sum > 0){
                i += k;
            } else {
                count++;
                i += k + 1;
            }
        }
    }

    cout << count << endl;
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