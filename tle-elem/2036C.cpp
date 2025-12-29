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

    int q;
    cin >> q;

    bool ok = false;
    int l = 0, r = 0;
    while(q--){

    		int i;
    		char v;
	    	cin >> i >> v;

	    	if(s.size() < 4){
    			cout << "NO" << endl;
    		} 

	    	s[i-1] = v;

	    	if(l && r && s.substr(l, 4) == "1100"){
	    		cout << "YES" << endl;
	    	} else {
	    		bool flag = false;
	    		for(int i = 1; i < s.size() - 3; i++){
		    		if(s.substr(i,4) == "1100"){
		    			cout << "YES" << endl;
		    			ok = true;
		    			flag = true;
		    			l = i;
		    			r = i+3;
		    			break;
		    		}
		    	}

		    	if(!flag){
		    		cout << "NO" << endl;
		    	}

    	}
    }

}

int main() {
    fast(); 

    int t = 1;
    cin >> t; 

    while (t--) solve();
}
    