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
    cin >> n;
    vector<int> a(n), b(n);

    for(int i = 0; i < n; i++){
    	cin >> a[i];
    }

    for(int i = 0; i < n; i++){
    	cin >> b[i];
    }

    unordered_map<int,int> A, B;

    for(int i = 0; i < n; i++){
    	int x = a[i];
    	int r = i;
    	while(r < n && a[r] == x){
    		r++;
    	}

    	A[x] = max(A[x], r - i);
    	i = --r;
    }

    for(int i = 0; i < n; i++){
    	int x = b[i];
    	int r = i;
    	while(r < n && b[r] == x){
    		r++;
    	}

    	B[x] = max(B[x], r - i);
    	i = --r;
    }
    
    // for(auto [x,y] : A){
    // 	cout << x << " " << y;
    // }

    // cout << endl;
    int ans = 0;
    for(auto [x,y] : A){
    	ans = max(ans, y + B[x]);
    }

    for(auto [x,y] : B){
    	ans = max(ans, y + A[x]);
    } 

    cout << ans << endl;
}

int main() {
    fast(); 

    int t = 1;
    cin >> t; 

    while (t--) solve();
}