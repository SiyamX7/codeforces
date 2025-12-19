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
	    }

	    	count++;
	    	n -= 4;
	    

	    count += n / 3;

	    cout << "Case " << i << ": " <<  count << endl;
    }
}
