#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define pb push_back
#define srt(x) sort(x.begin(), x.end())
#define rsrt(x) sort(x.rbegin(), x.rend())
#define vll vector<long long>
#define fast ios::sync_with_stdio(false); cin.tie(nullptr)
#define pop(x) __builtin_popcount(x) // x -> int

int main() {
    fast;
    int t;
    cin >> t;
    while(t--){
    	ll n;
    	cin >> n;

    	if(n < 2){
    		cout << "no" << endl;
    		continue;
    	}

    	if(n % 2 == 1){
    		cout << "yes" << endl;
    	} else {

    		while(n % 2 == 0){
    			n /= 2;
    		}

    		if(n != 1) {
    			cout << "yes" << endl;
    		} else {
    			cout << "no" << endl;
    		}
    	}
    }
}