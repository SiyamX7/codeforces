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
    string s;
    cin >> s;

    for(int i = 0; i < s.size(); i++){
    	int x = s[i] - '0';
    	int y;

    	if(i == 0){
    		int temp = '9' - s[i];
    		if(temp == 0){
    			y = '9';
    		} else {
    			y = temp;
    		}

    	} else {
    		y = '9' - s[i];
    	}

    	cout << min(x,y);
    }
}

int main() {
    fast(); 

    int t = 1;
    // cin >> t; 

    while (t--) solve();
}
