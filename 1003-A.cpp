#include <bits/stdc++.h>
using namespace std;                   

int main() {
	int n;
	cin >> n;
	while(n--){
		string s;
		cin >> s;
		s[s.length()-2] = 'i';
		s[s.length()-1] = ' ';
		cout << s << endl;
	}
}