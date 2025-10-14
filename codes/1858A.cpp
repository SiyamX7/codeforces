#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define vb vector<bool>
#define fast ios::sync_with_stdio(0); cin.tie(0);

using namespace std;                   

int main() {
    fast;
 	ll t; cin >> t;
 	while (t--) {
 	   		ll a, b, c;
 	   		cin >> a >> b >> c;
 	   		if(c % 2){
 	   			if(a >= b) {
 	   				cout << "First" << endl;
 	   			} else {
 	   				cout << "Second" << endl;
 	   			}
 	   		} else {
 	   			if(b >= a) {
 	   				cout << "Second" << endl;
 	   			} else {
 	   				cout << "First" << endl;
 	   			}   			
 	   		}
 	   }   
}