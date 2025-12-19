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
   	string a, b;
   	cin >> a >> b;
   	int m = a.size(), n = b.size();

   	vector<vector<int>> dp (m+1, vector<int>(n+1, 0));
   	int MAX = 0;

   	for(int i = 1; i <= m; i++){
   		for(int j = 1; j <= n; j++){
   			if(a[i-1] == b[j-1]){
   				dp[i][j] = 1 + dp[i-1][j-1];
   				MAX = max(MAX, dp[i][j]);
   			} else {
   				dp[i][j] = 0;
   			}
   		}
   	}

   	cout << m + n - 2 * MAX << endl;
}

int main() {
    fast(); 

    int t = 1;
    cin >> t; 

    while (t--) solve();
}
    