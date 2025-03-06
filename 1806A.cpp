#include <bits/stdc++.h>
#include <cstdlib>
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
 	while(t--){
 		 	int x1, y1, x2, y2;
 			cin >> x1 >> y1 >> x2 >> y2;

 			int diff = y2 - y1;
 			x1 += diff;

 			if(x1 < x2 || y2 < y1) {
 				cout << -1 << endl;
 				continue;
 			}

 			cout << diff + abs(x1 - x2) << endl;
 	}
}