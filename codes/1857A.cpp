#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define vb vector<bool>
#define fast ios::sync_with_stdio(0); cin.tie(0);

using namespace std;                   

int main() {
    fast;
 	ll t;
 	cin >> t;
 	while (t--) {
 	   		ll n;
 	   		cin >> n;
 	   		ll odd = 0, even = 0;
 	   		for(int i = 0; i < n; i++){
 	   			int x; cin >> x;

 	   			if(x % 2) odd++;
 	   			else even++;
 	   		}
 	   		// cout << odd << " " << even << endl;

 	   		if(even > 0 && odd % 2 == 0){
 	   			cout << "yes" << endl;
 	   		} else if (even == 0 && odd % 2 == 0){
 	   			cout << "yes" << endl;
 	   		} else {
 	   			cout << "no" << endl;
 	   		}
 	   }   
}

// if(sum == even number) yes;
// else no [from jiangly]