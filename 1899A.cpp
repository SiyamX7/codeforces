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
 		int n;
 		cin >> n;
 		vi v(n), vv;

 		for(int &i : v) cin >> i;
 		
 		if(v[0] == 1) cout << "yes" << endl;
 		else cout << "no" << endl;
 	}   
}