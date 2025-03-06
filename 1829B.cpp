#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define pb push_back
#define srt(x) sort(x.begin(), x.end())
#define vll vector<long long>
#define fast ios::sync_with_stdio(false); cin.tie(nullptr);

using namespace std;                   

int main() {
    fast;
 	int t;
 	cin >> t;
 	while (t--) {
 		int n; 
 		cin >> n;

 		vi v(n);
 		for(int &i : v) cin >> i;
 		int count = 0;

 		for(int i = 0; i < n; ){
 			if(v[i] == 0){
 				int temp = 0;
 				while(i < n && v[i] != 1){
 					temp++;
 					count = max(temp, count);
 					i++;
 				}
 			} else {
 				i++;
 			}
 		}
 		cout << count << endl;
 	}   
}