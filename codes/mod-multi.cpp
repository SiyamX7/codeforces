#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	
	int a, b, m;
	cin >> a >> b >> m;
	cout << (1LL * (a % m) * (b % m)) % m;   
}
