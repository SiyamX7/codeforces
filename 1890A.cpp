#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define vb vector<bool>
#define fast ios::sync_with_stdio(0); cin.tie(0);

using namespace std;                   

int main() {
    int t;
    cin >> t;
    while(t--){
    	int n;
    	cin >> n;
    	vi v(n);
    	map<int, int> mp;

    	for(int &i : v){
    		cin >> i;
    		mp[i]++;
    	}

    	if(mp.size() > 2) {
    		cout << "no" << endl;
    	} else {
    		if(abs(mp.begin()->second - mp.rbegin()->second) < 2) cout << "yes" << endl;
    		else cout << "no" << endl;
    	}
    }
}