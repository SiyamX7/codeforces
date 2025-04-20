#include <bits/stdc++.h>
using namespace std;                   

int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; i++){
		cin >> v[i];
	}

	int mx = v[0], mn = v[0];
	int count = 0;
	for(int i = 1; i < n; i++){
		if(v[i] > mx){
			count ++;
			mx = v[i];
		}
		else if(v[i] < mn){
			count++;
			mn = v[i];
		}
	}
	// cout << mx << " " << mn << endl;
	cout << count;
}