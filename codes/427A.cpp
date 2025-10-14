#include <bits/stdc++.h>
using namespace std;                   

int main() {
	int n;
	cin >> n;
	int police = 0;
	int cases = 0;
	for(int i = 0; i < n; i++){
		int x; 
		cin >> x;

		if(police == 0 && x == -1){
			cases++;
		} else if(police > 0 && x == -1){
			police--;
		} else {
			police += x;
		}
	}

	cout << cases << endl;
}