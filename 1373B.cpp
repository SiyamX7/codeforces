#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define pb push_back
#define sort(x) sort(x.begin(), x.end())
#define rsort(x) sort(x.rbegin(), x.rend())
#define vll vector<long long>
#define fast ios::sync_with_stdio(false); cin.tie(nullptr)
#define pop(x) __builtin_popcount(x) // x -> int

string dhur(){
	string s;
	cin >> s;
	int a = 0, b = 0;

	for(char x : s){
		if(x == '1'){
			a++;
		} else if (x == '0') {
			b++;
		}
	}

	if(min(a,b) % 2 == 1) {
		return "DA";
	}
	return "NET";
}

int main() {
    fast;
	
	int t;
	cin >> t;
	while (t--) {
		cout << dhur() << endl;
   }   
}