#include <bits/stdc++.h>
using namespace std;

#define ll  long long              
#define pb  push_back
#define eb  emplace_back                                 
#define bug(x) cerr << #x << " = " << x << endl                 
 
void fast() {ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
template <typename T>
void print(const vector<T>& vec) {for (const auto& val : vec) {cout << val << " ";}cout << endl;}


int main() {
    fast(); 

    int t = 1;
    cin >> t; 

    for(int i = 1; i <= t; i++){
    	ll count = 0;
	    ll n;
	    cin >> n;

	    if(n < 4){
	    	cout << "Case " << i << ": " << 0 << endl;
	    	continue;
	    } else if(n >= 4 && n < 7){
	    	cout << "Case " << i << ": " << 1 << endl;
	    } else if(n == 7){
	    	cout << "Case " << i << ": " << 2 << endl;
	    } else {
	    	n -= 7;
	    	count += 2;

	    	count += 2 * (n / 5);

	    	n = n % 5;

	    	if(n >= 3) count++;
	    	cout << "Case " << i << ": " <<  count << endl;
	    }
    }
}
