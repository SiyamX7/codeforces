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
    int n = s.size();
    int x = 0, y = 0;

    for(int i = 0; i < n; i++){
    	if(s[i] == '0') x++;
    	else y++;
    }

    int count = 0;

    for(int i = 0; i < n; i++){
    	if(s[i] == '0' && y > 0){
    		count++;
    		y--;
    	} else if(s[i] == '1' && x > 0){
    		count++;
    		x--;
    	} else {
    		break;
    	}
    }

    cout << n - count << endl;
}

int main() {
    fast(); 

    int t = 1;
    cin >> t; 

    while (t--) solve();
}
    