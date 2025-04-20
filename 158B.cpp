#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;                   

int main() {
	int n;
	cin >> n;
	unordered_map<int, int> mp;

	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		mp[x]++;
	}

	// for(auto val : mp){
	// 	cout << val.first << " " << val.second << endl;
	// }

	int result = mp[4] + mp[3];

	if(mp[3] >= mp[1]){
 		mp[1] = 0;
	} else {
		mp[1] = mp[1] - mp[3];
	}

	if(mp[2] % 2 == 0){
		result += mp[2] / 2;
	} else {
		result += mp[2] / 2 + 1;
		mp[1] -= 2;
	}

	result += (mp[1] + 3) / 4;

	cout << result;
}