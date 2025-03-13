#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define pb push_back
#define srt(x) sort(x.begin(), x.end())
#define rsrt(x) sort(x.rbegin(), x.rend())
#define vll vector<long long>
#define fast ios::sync_with_stdio(false); cin.tie(nullptr)
#define pop(x) __builtin_popcount(x) // x -> int

int main() {
    fast;
 	int t;
 	cin >> t;
 	while(t--){
 		int n;
 		cin >> n;
 		vi v(n);
 		for(int &i : v) cin >> i;

 		bool flag = false;
 		for(int i = 0; i < n; i++){
 			int left = i + 1, right = n - 1;

 			while (left < right and !flag) {
 				if(v[i] < v[left] and v[left] > v[right]){
 					cout << "YES" << endl;
 					cout << i + 1 << " " << left + 1 << " " << right + 1 << endl;
 					flag = true;
 					break;
 				} else if (v[left] < v[i]){
 					left++;
 				} else {
 					right--;
 				}
 			}

 		}

 		if(!flag){
 			cout << "NO" << endl;
 		}
 	}   
}