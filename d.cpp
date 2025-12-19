#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll gcd(ll a, ll b) { return b==0 ? a : gcd(b,a%b); }

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int MAX_A = 0;
    for(int i=0;i<n;i++) {
        cin >> a[i];
        MAX_A = max(MAX_A, a[i]);
    }

    // Step 1: Frequency array
    vector<int> freq(MAX_A+1,0);
    for(int x:a) freq[x]++;

    // Step 2: Candidate maximum gcd comes from i=j pair (a_i itself)
    ll max_gcd = 0;
    ll count = 0;
    for(int x=0;x<=MAX_A;x++){
        if(freq[x]==0) continue;
        // i=j pair
        if(x>max_gcd){
            max_gcd = x;
            count = 1LL*freq[x]*freq[x];
        } else if(x==max_gcd){
            count += 1LL*freq[x]*freq[x];
        }
    }

    // Step 3: Check i!=j pairs in efficient way
    // Only pairs where x!=y and freq[x]>0 and freq[y]>0
    // Loop descending to prioritize largest gcd
    for(int i=MAX_A;i>=0;i--){
        if(freq[i]==0) continue;
        for(int j=i-1;j>=0;j--){
            if(freq[j]==0) continue;
            ll g = gcd(i^j, i&j);
            if(g>max_gcd){
                max_gcd = g;
                count = 2LL*freq[i]*freq[j]; // ordered pairs (i,j) and (j,i)
            } else if(g==max_gcd){
                count += 2LL*freq[i]*freq[j];
            }
        }
    }

    cout << max_gcd << " " << count << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--) solve();
}
