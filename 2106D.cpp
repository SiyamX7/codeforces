#include <bits/stdc++.h>
#include <climits>
using namespace std;

int solve(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);

    unordered_set<int> s;
    vector<pair<int,int>> pr;

    int mn = INT_MAX;
    int mx = 0;

    for(int i = 0; i < n; i++){
        cin >> a[i];
        mn = min(a[i], mn);
        mx = max(a[i], mx);
    }

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;

        if(x == a[i]) return 0; 

        if(x != -1){ 
            s.insert(x);
            pr.push_back({x,i});
        }
        b[i] = x; 
    }

    if(s.size() == 1){
        return a[pr[0].second] + b[pr[0].second];
    } else if(s.size() > 1) {
        return 0;
    } else {
        return  (mn + k) - mx + 1;
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--){
        cout << solve() << endl;
    }
}
