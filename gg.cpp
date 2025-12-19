#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
#define pb push_back
void fast() { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); }

void solve() {
    ll n;
    cin >> n;
    vector<ll> v(n);
    unordered_map<ll, ll> freq;
    ll mx = 0;
    for(ll i = 0; i < n; i++){
    	cin >> v[i];
    	freq[v[i]]++;
    	mx = max(mx , v[i]);
    }

    ll g = 0, count = 1;

    if(mx % 2 == 0){
    	if(freq[1] > 0){
    		g = mx + 1;
    		count = freq[mx] * freq[mx] + freq[1];
    	} else {
    		g = mx;
    		count = freq[mx] * freq[mx];
    	}
    } else {
    	 g = mx;
    	 count = freq[0] * freq[mx] * 2 + freq[mx] * freq[mx];
    }

    cout << g << " " << count << endl;
}

int main() {
    fast();
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}