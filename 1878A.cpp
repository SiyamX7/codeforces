#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define vb vector<bool>
#define fast ios::sync_with_stdio(0); cin.tie(0);

using namespace std;                   

int main() {
    fast;
    int t;
    cin >> t;
    while(t--){
    	int n, k;
    	cin >> n >> k;
    	bool flag = false;
    	for(int i = 0; i < n; i++){
    		int x;
    		cin >> x;
    		if (x == k) flag = true;
    	}

    	if(flag) cout << "YES" << endl;
    	else cout << "NO" << endl;
    }
}