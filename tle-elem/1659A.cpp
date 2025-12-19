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
    int n, r, b;
    cin >> n >> r >> b;

    int div = r / (b+1);
    int rem = r % (b+1);

    string s = "";

    for(int i = 0; i < b+1; i++){
    	s += string(div, 'R');

    	if(rem > 0) {
    		s += 'R';
    		rem--;
    	}

   		if(i < b){
   			s += 'B';
   		}
    }

    cout << s << endl;
}

int main() {
    fast(); 

    int t = 1;
    cin >> t; 

    while (t--) solve();
}
    