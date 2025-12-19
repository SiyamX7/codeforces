#include <bits/stdc++.h>
using namespace std;

#define ll  long long              
#define pb  push_back
#define eb  emplace_back                                 
#define bug(x) cerr << #x << " = " << x << endl                 
 
void fast() {ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
template <typename T>
void print(const vector<T>& vec) {for (const auto& val : vec) {cout << val << " ";}cout << endl;}

void solve(){
    int n;
    char c;
    string s;

    cin >> n >> c >> s;

    if(c == 'g') {
    	cout << 0 << endl;
    	return;
    }

    s += s;
    set<ll> st;

    ll r = 0;

	for(ll l = 0; l < n; ){
		if(s[l] == c){
			r = l + 1;
			while(r < n * 2 && s[r] != 'g'){
				r++;
			}

			st.insert(r - l);
			l = r;
		} else {
			l++;
		}
	}

	cout << *st.rbegin() << endl;

}

int main() {
    fast(); 

    int t = 1;
    cin >> t; 

    while (t--) solve();
}
    















    #include <bits/stdc++.h>
using namespace std;

#define ll  long long              
#define pb  push_back
#define eb  emplace_back                                 
#define bug(x) cerr << #x << " = " << x << endl                 
 
void fast() {ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
template <typename T>
void print(const vector<T>& vec) {for (const auto& val : vec) {cout << val << " ";}cout << endl;}

void solve(){
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n);

    for(ll i = 0; i < n; i++) cin >> v[i];

    sort(v.begin(), v.end(), greater<>());

	ll count = 0, rem = n;

	for(ll i = 0; i < n; i++){
		ll need = (k + v[i] - 1 )/ v[i];

		if(need * v[i] == k){
			if(need + 1 <= rem){
				count++;
				rem -= need + 1;
			} else break;
		} 

		else if(need * v[i] > k){
			if(need <= rem){
				count++;
				rem -= need;
			} else break;
		}
	}

	cout << count << endl;
}

int main() {
    fast(); 

    int t = 1;
    cin >> t; 

    while (t--) solve();
}
    