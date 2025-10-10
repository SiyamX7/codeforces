#include <bits/stdc++.h>
using namespace std;

void solve(){
    
    int k, a, b;
    cin >> k >> a >> b;
    vector<int> v(a), vv(b);

    for(int i = 0; i < a; i++) cin >> v[i];
   	for(int i = 0; i < b; i++) cin >> vv[i];

   	vector<int> ans;

   	int mn = min(a,b);
   	int mx = max(a,b);

   	int i = 0;
   	while(i != mn){
   		if(v[i] == 0) ans.push_back(0), k++;
   		if(vv[i] == 0) ans.push_back(0), k++;
   		if(v[i] > k || vv[i] > k) {
   			cout << -1 << endl;
   			return;
   		}
   		if(v[i] != 0) ans.push_back(v[i]);
   		if(vv[i] != 0) ans.push_back(vv[i]);

   		i++;
   		// cout << i << " ";
   	}
   	// cout << k;
   	if(a > b){
   		for(int j = i; j < mx; j++){
   			if(v[i] == 0) ans.push_back(0),k++;
   			else if(v[i] > k){
   				cout << -1 << endl;
   				return;
   			} else {
   				ans.push_back(v[i]);
   			}
   		}
   	} else if(a < b){
   		for(int j = i; j < mx; j++){
   			if(vv[i] == 0) ans.push_back(0),k++;
   			else if(vv[i] > k){
   				cout << -1 << endl;
   				return;
   			} else {
   				ans.push_back(vv[i]);
   			}
   		}
   	}

   	for(int i : ans) cout << i << " ";
   	cout << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
    	solve();
    }
}   