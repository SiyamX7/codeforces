#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	
	int n;
	cin >> n;
	vector<int> v(n);

	for(int i = 0; i < n; i++){
		cin >> v[i];
	}   

	vector<int> prefix(n);

	prefix[0] = v[0];

	for(int i = 1; i < n; i++){
		prefix[i] = prefix[i-1] ^ v[i];
	}

	int q;
	cin >> q;
	while(q--){
		int l, r;
		cin >> l >> r;
		cout << "Xor from l to r is : " << endl;
		cout << (prefix[l-1] ^ prefix[r]) << endl;

		/*ekoi jinis er x-or 0 hoy.
		mane l = 1,2,3,4,5
			 r = 1,2,3,4,5,6,7
			 pre[l-1] ^ pre[r] --> 6,7
			 baki gula 0 hoye jabe */
	}
}
