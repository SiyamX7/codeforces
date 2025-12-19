#include <bits/stdc++.h>
#include <string>
using namespace std;

#define ll  long long              
#define pb  push_back
#define eb  emplace_back                                 
#define bug(x) cerr << #x << " = " << x << endl                 
 
void fast() {ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
template <typename T>
void print(const vector<T>& vec) {for (const auto& val : vec) {cout << val << " ";}cout << endl;}

void solve(){
	int n;
	cin >> n;

	string s = to_string(n);

	while(1){
		for(int i = 0; i < s.size(); i++){
			int k = s[i] - '0';
			if(n % k != 0){
				n++;
				break;
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
    