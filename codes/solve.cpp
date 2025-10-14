#include <bits/stdc++.h>
#include <climits>
#include <unordered_set>
#include <vector>
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k;
		vector<int> a(n), b(n); 
		unordered_set<int> s;

		for(int i = 0; i < n; i++){
			cin >> a[i];
		}

		for(int i = 0; i < n; i++){
			cin >> b[i];
		}

		bool same = false;
		bool gg = false;

		int mn = INT_MAX;
		int mx = INT_MIN;

		for(int i = 0; i < n; i++){
			if(a[i] == b[i]){
				// cout << 0 << endl;
				same = true;
			} else if(b[i] != -1){
				// cout << 1 << endl;
				// flag = true;
				// break;
				s.insert(a[i] + b[i]);
			} else {
				mn = min(mn, a[i]);
				mx = max(mx, a[i]);
			}
		}

		if(same || s.size() > 1){
			cout << 0 << endl;
		} else if (s.size() == 1){
			cout << 1 << endl;
		} else {
			cout << k - mx + mn + 1 << endl;
		}

	}
}