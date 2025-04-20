#include <bits/stdc++.h>
using namespace std;                   

int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	for(int &val : v){
		cin >> val;
	}
	int mx = INT_MIN, mn = INT_MAX;
	int firstMaxPos, lastMinPos;

	for(int i = 0; i < n; i++){
		if(v[i] > mx){
			mx = max(mx, v[i]);
			firstMaxPos = i;
		}

		if(v[i] <= mn){
			mn = min(mn, v[i]);
			lastMinPos = i;
		}
	}

	// cout << firstMaxPos << " " << lastMinPos << endl;

	if(firstMaxPos < lastMinPos) {
		cout << firstMaxPos + (n-1) - lastMinPos << endl;
	} else {
		cout << firstMaxPos + (n-1) - lastMinPos - 1 << endl;
	}
}