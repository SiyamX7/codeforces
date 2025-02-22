#include <bits/stdc++.h>
#define ll long long
#define vi vector<long long>
#define vii vector<long long>
#define vb vector<bool>
using namespace std;                   

ll nCr (ll n, ll r){
	if(n - r > r) r = n-r;

	ll res = 1;

	for(int i = 0; i < r; i++){
		res *= (n - i);
		res /= (i + 1);
	}

	return res;
}

ll nPr(ll n, ll r){
	ll res = 1;

	for(int i = 0; i < r; i++){
		res *= (n - i);
	}

	return res;
}

int main() {
	ll n = 3, r = 3;
	cout << nCr(n, r) << endl;
	cout << nPr(n, r) << endl;
}