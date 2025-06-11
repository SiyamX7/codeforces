#include <bits/stdc++.h>
using namespace std;
int main(){
	int k;
	cin >> k;
	string a, b;
	cin >> a >> b;
	int n = a.size();

	int count = 0;
	for(int i = 0; i < n; i++){
		if(a[i] == b[i]) count++;
	}

	if(count < k){
		cout << n - k - count << endl;
	} else {
		cout << n + k - count << endl;
	}
}