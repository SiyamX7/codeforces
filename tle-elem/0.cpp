#include<bits/stdc++.h>

using namespace std;
#define ll long long

void solve() {
   ll n , h , k;
   cin >> n >> h >> k;
   vector < ll > vec(n);
   vector < ll > pre(n+1);
   ll mx = INT_MIN;
   for(ll i = 0; i < n; i++)
   {
    cin >> vec[i];
    pre[i+1] = pre[i] + vec[i];
    mx = max(vec[i] , mx);
   }
   ll sum = pre[n];
  // cout << sum << endl;
   ll time = h / sum;
   ll ans1 = 0;
   if(h % sum)  ans1 = time*( n + k);
   else{
    cout << time * n + (time-1) * k << endl;
    return;
   }
  
   ll need = h - sum * time;


   ll mx1 = 0;
    for (long long x : vec) {
        mx1 = max(mx1, x);
    }

   
    ll new_sum = 0;
    ll mn_range = LLONG_MAX;

    for (int t = 1; t <= n; t++) {
        new_sum += vec[t-1];
        mn_range = min(mn_range, vec[t-1]);

        
        ll b_damage = max(new_sum, new_sum - mn_range + mx1);

        if (b_damage >= need) {
            cout << ans1 + t << endl; 
            return ;
        }
    }
       cout << ans1 + n << endl; 
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