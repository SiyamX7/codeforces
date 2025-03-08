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

 		int x = n + 1;
 		
 		for(int i = 0; i < n; i++){
 			int a;
 			cin >> a;
 			cout << x - a << " ";
 		}   
 		cout << endl;
 	}   
}