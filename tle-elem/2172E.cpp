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

const int INF = 4e18;
const int MOD = 1e9+7;

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

vector<vector<int>> two, three, four;

void solve(int _){
    int n, j, k;
    cin >> n >> j >> k;
    vector<int> s, t;

    if(n == 12){
    	s = two[j-1];
    	t = two[k-1];
    }

    if(n == 123){
    	s = three[j-1];
    	t = three[k-1];
    }

    if(n == 1234){
    	s = four[j-1];
    	t = four[k-1];
    }

    int x = 0, y = 0;
    for(int i = 0; i < s.size(); i++){
    	for(int j = 0; j < t.size(); j++){
    		if(i == j && s[i] == t[j]){
    			x++;
    		}

    		if(i != j && s[i] == t[j]){
    			y++;
    		}
    	}
    }

   	cout << x << "A" << y << "B";
}

signed main(){
    fast();

    vector<vector<int>> a = {{1,2},{1,2,3},{1,2,3,4}};

    for(int i = 0; i < 3; i++){
    	if(i == 0){
    		do{
    			two.pb(a[i]);
    		}while(next_permutation(all(a[i])));
    	}

    	if(i == 1){
    		do{
    			three.pb(a[i]);
    		}while(next_permutation(all(a[i])));
    	}
    	
    	if(i == 2){
    		do{
    			four.pb(a[i]);
    		}while(next_permutation(all(a[i])));
    	}    	
    }

    // print(two);
    // print(three);
    // print(four);

    int T = 1; 
    cin >> T;
    for(int _ = 1; _ <= T; _++){
        solve(_);
        cout << endl;
    }

    return 0;
}
    