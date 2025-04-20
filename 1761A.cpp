#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n, a, b;
		cin >> n >> a >> b;
		if(n == a and n == b and a == b){
			cout << "yes" << endl;
		} else if(n - (a + b) >= 2) {
			cout << "yes" << endl;
		} else {
			cout << "no" << endl;
		}
	}
}