#include <bits/stdc++.h>
using namespace std;

void solve(){
	int a,b, xk, yk, xq, yq;
	cin >> a >> b >> xk >> yk >> xq >> yq;

	int dx[8] = { a,  a, -a, -a,  b,  b, -b, -b };
	int dy[8] = { b, -b,  b, -b,  a, -a,  a, -a };

	int count = 0;

	//The knightttttty attacks the king from position (xK + x, yK + y)

	for(int k = 0; k < 8; k++){	
		int u = xk + dx[k] - xq;
		int v = yk + dy[k] - yq;

		u = abs(u);
		v = abs(v);

		if((u == a && v == b) || (u == b && v == a))
			count++;
	}

	if(a == b) count /= 2;
	cout << count << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--) solve();
}   