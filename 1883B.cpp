#include <bits/stdc++.h>
#include <unordered_map>
#include <utility>
using namespace std;

int main(){
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	map<char, int> mp;
	for(char i : s){
		mp[i]++;
	}

	vector<char> v;
	for(auto i : mp){
		v.push_back(i.first);
	}

	sort(v.begin(), v.end(), [&](char a, char b){
		return mp[a] < mp[b];
	});

	for(auto i : mp){
		cout << i.first << " " << i.second << endl;
	}
}