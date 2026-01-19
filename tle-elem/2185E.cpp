#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define eb emplace_back
#define bug(x) cerr << #x << " = " << x << endl
#define endl '\n'

#define rem(v,x) (v).erase(remove((v).begin(), (v).end(), (x)), (v).end())
#define leftrotate(v,k) rotate((v).begin(), (v).begin() + ((k) % (v).size()), (v).end())

#define popcountll(x) __builtin_popcountll(x)
#define lzll(x) __builtin_clzll(x)
#define tzll(x) __builtin_ctzll(x)

void fast() { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); }
template <typename T>
void print(const vector<T>& vec) { for (const auto& val : vec) cout << val << " "; cout << endl; }

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n), b(m);
    for(int &x : a) cin >> x;
    for(int &x : b) cin >> x;

    string s;
	cin >> s;

    sort(b.begin(), b.end());
	
	map<int, vector<int>> Ldead, Rdead;
	
	for(int i = 0; i < n; i++){
		auto it = lower_bound(b.begin(), b.end(), a[i]);

		if(it != b.end()){
			int d = *it - a[i];
			Rdead[d].pb(i);
		}

		if(it != b.begin()){
			int d = a[i] - *(--it);
			Ldead[d].pb(i);
		}
	}

	int pos = 0;
	int L = 0, R = 0;
	int dead = 0;

	vector<bool> isDead(n, false);

	for(char c : s){
		if(c == 'L') pos--;
		else pos++;

		if(-pos > L){
			L = -pos;

			for(int x : Ldead[L]){
				if(!isDead[x]){
					isDead[x] = true;
					dead++;
				}
			}
		}

		if(pos > R){
			R = pos;

			for(int x : Rdead[R]){
				if(!isDead[x]){
					isDead[x] = true;
					dead++;
				}
			}
		}

		cout << n - dead << " ";
	}

	cout << endl;
}

signed main() {
    fast();
    int t = 1;
    cin >> t;
    while (t--) solve();
}
    