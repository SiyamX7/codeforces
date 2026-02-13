#include <bits/stdc++.h>
using namespace std;

static inline void fast(){ ios::sync_with_stdio(false); cin.tie(nullptr); }

#define int long long
#define i128 __int128_t
#define u128 __uint128_t
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define popcount(x) __builtin_popcountll(x)
#define clz(x) __builtin_clzll(x)
#define ctz(x) __builtin_ctzll(x)
#define endl '\n'
#define yes cout << "YES\n"
#define no  cout << "NO\n"
#define test cout << "Test #" << _ << ":\n"
#define pb push_back
#define eb emplace_back
#define f first
#define s second

/* ================= UTILS ================= */
template<class T> void uniq(vector<T>&v){ sort(all(v)); v.erase(unique(all(v)),v.end()); }
template<class T> void remVAL(vector<T>&v,T x){ v.erase(remove(all(v),x),v.end()); }
template<class T> void remID(vector<T>&v,int i){ if(i>=0 && i<sz(v)) v.erase(v.begin()+i); }
template<class T> void rot(vector<T>&v,int k){ if(v.empty()) return; k%=sz(v); rotate(v.begin(),v.begin()+k,v.end()); }

/* ================= PRINT ================= */
template<class T> void print(const T&x){ cout<<x<<'\n'; }
template<class A,class B> void print(const pair<A,B>&p){ cout<<p.f<<" "<<p.s<<'\n'; }
template<class T> void print(const vector<T>&v){ for(auto &x:v) cout<<x<<" "; cout<<'\n'; }
template<class A,class B> void print(const vector<pair<A,B>>&v){ for(auto &p:v) cout<<p.f<<" "<<p.s<<'\n'; }
template<class T> void print(const set<T>&s){ for(auto &x:s) cout<<x<<" "; cout<<'\n'; }
template<class K,class V> void print(const map<K,V>&m){ for(auto &p:m) cout<<p.f<<" : "<<p.s<<'\n'; }
template<class T> void print(const vector<vector<T>>&v){ for(auto &r:v){ for(auto &x:r) cout<<x<<" "; cout<<'\n'; } }

/* ================= i128 IO ================= */
i128 read_i128(){ string s; cin>>s; i128 x=0; int i=0,sg=1; if(s[0]=='-') sg=-1,i=1; for(;i<sz(s);i++) x=x*10+(s[i]-'0'); return x*sg; }
void print(i128 x){ if(x==0){cout<<0<<'\n';return;} if(x<0) cout<<"-",x=-x; string s; while(x){s.pb('0'+x%10);x/=10;} reverse(all(s)); cout<<s<<'\n'; }

const int INF = 4e18;
const int MOD = 998244353;
const int MAX = 200005;
int f[MAX];

void fact(){
	f[0] = f[1] = 1;
	for(int i = 2; i < MAX; i++){
		f[i] = (f[i-1] * i) % MOD;
	}
}

void solve(int _){
    string s;
    cin >> s;

    int n = s.size();
    int a = 0, b = 1;

    for(int i = 0; i < n; ){
    	char c = s[i];
    	int j = i;

    	while(i < n && s[i] == c) i++;
    	
    	int len = i - j;
    	a += len - 1;
    	b = (b * len) % MOD;
    }

    b = (b * f[a]) % MOD;

    cout << a << " " << b;
}

signed main(){
    fast();
    fact();
    int tc = 1; 
    cin >> tc;
    for(int t = 1; t <= tc ; t++){
        solve(t);
        cout << endl;
    }

    return 0;
}
    