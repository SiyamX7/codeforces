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
 	while(t--){
 		int x;
 		cin >> x;
        int count = 0;
 		while(x > 10){
            x /=10;
            count += 9;
        }
        count += x;
        cout << count << endl;
 	}   
}