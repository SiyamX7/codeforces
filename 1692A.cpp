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
 	while (t--) {
 	   		int a, b, c, d;
 	   		cin >> a >> b >> c >> d;
 	   		int count = 0;
 	   		if(a < b) count++;
 	   		if(a < c) count++;
 	   		if(a < d) count++;
 	   		cout << count << endl;
 	   }   
}