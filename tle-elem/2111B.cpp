#include <bits/stdc++.h>
using namespace std;

#define ll  long long              
#define pb  push_back
#define eb  emplace_back                                 
#define bug(x) cerr << #x << " = " << x << endl                 
 
void fast() {ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
template <typename T>
void print(const vector<T>& vec) {for (const auto& val : vec) {cout << val << " ";}cout << endl;}

vector<int> fib(21);
	
void solve(){
    int n, m;
    cin >> n >> m;

    string s = "";

    while(m--){
    	vector<int> v(3);
   		for(int i = 0; i < 3; i++) cin >> v[i];
    	sort(v.begin(), v.end());

    	vector<int> g(3);
    	g[0] = fib[n];
    	g[1] = fib[n];
    	g[2] = fib[n] + fib[n-1];

    	bool flag = false;

    	for(int i = 0; i < 3; i++){
    		if(v[i] < g[i]){
    			s += '0';
    			flag = true;
    			break;
    		}
    	}

    	if(!flag) s += '1';
    }

   	cout << s << endl;
}

int main() {
    fast(); 

    fib[1] = 1;
    fib[2] = 2;

    for(int i = 3; i < 21; i++){
    	fib[i] = fib[i-1] + fib[i-2];
    }

    int t = 1;
    cin >> t; 

    while (t--) solve();
}
    