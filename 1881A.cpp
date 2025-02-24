#include <bits/stdc++.h>
#include <string>
#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define vb vector<bool>
#define fast ios::sync_with_stdio(0); cin.tie(0);

using namespace std;                   

int main() {
 	int t; cin >> t;
 	while(t--){
 		int n, m;
 		cin >> n >> m;
 		string x, s;
 		cin >> x >> s;
 		int count = 0;
 		while(x.find(s) == string::npos && count < 10){
 			x += x;
 			count++;
 		}

 		if(count  > 9){
 			cout << -1 << endl;
 		} else {
 			cout << count << endl;
 		}
 	}   
}