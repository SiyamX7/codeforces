#include <bits/stdc++.h>
#include <cmath>
using namespace std;                   

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n, l;
	cin >> n >> l;
	vector<double> v(n);
	double error = 1e-9;
	bool zero = false, last = false;
	for(int i = 0; i < n; i++){
		double x;
		cin >> x;
		v[i] = x;
		if(fabs(x) < error) zero = true;
		if(fabs(l - x) < error) last = true;
	}

	sort(v.begin(), v.end());

	double mx = 0.0;
	for(int i = 1; i < n; i++){
		double x = (v[i] - v[i-1]) / 2.0;
		// cout << x << endl;
		mx = max(x, mx);
	}
	if(!zero) mx = max(v[0], mx);
	if(!last) mx = max(l - v[n-1], mx);
	cout << fixed << setprecision(10) << mx;
}
