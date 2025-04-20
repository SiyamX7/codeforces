#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define pb push_back
#define srt(x) sort(x.begin(), x.end())
#define vll vector<long long>
#define fast ios::sync_with_stdio(false); cin.tie(nullptr);

using namespace std;                   

int count(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	int left = 0, right = n - 1;
	int cnt = 0;
	while(left < right){
		if((s[left] == '0' && s[right] == '1') || (s[left] == '1' && s[right] == '0')) {
			cnt += 2;
			left++;
			right--;
		} else {
			break;
		}
	}
	return n - cnt;
}

int main() {
    fast;
 	int t;
 	cin >> t;
 	while(t--){
 		cout << count() << endl;
 	}   
}