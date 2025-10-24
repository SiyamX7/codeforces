#include <bits/stdc++.h>
using namespace std;

#define ll  long long              
#define pb  push_back
#define eb  emplace_back                                 
#define bug(x) cerr << #x << " = " << x << endl                 
 
void fast() {ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
template <typename T>
void print(const vector<T>& vec) {for (const auto& val : vec) {cout << val << " ";}cout << endl;}

void solve(){
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;

    int B = 0;
    for(int i = 0; i < n; i++) {
    	if(s[i] == 'B') B++;
    }
	
    while (q--) {
    	int x;
    	cin >> x;

    	if(B == 0) {
    		cout << x << endl;
    		continue;    	
    	}

    	int i = 0;
    	int count = 0;

    	while(x != 0){
    		if(s[i] == 'A'){
    			x -= 1;
    		} else {
    			x = x / 2;
    		}

    		count++;
    		i++;
    	
    		if(i == n) {
    			i = 0;
    		}
    	}

    	cout << count << endl;
    }
}

int main() {
    fast(); 

    int t = 1;
    cin >> t; 

    while (t--) solve();
}
    