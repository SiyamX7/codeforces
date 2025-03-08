#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define pb push_back
#define srt(x) sort(x.begin(), x.end())
#define vll vector<long long>
#define fast ios::sync_with_stdio(false); cin.tie(nullptr);
#define pop(x) __builtin_popcount(x) // x -> int
using namespace std;

string solve(){
        ll n, k;
        cin >> n >> k;

        if(n % 2 == 0) {
            return "yes";
        } else if(n >= k and (n - k) % 2 == 0){
            return "yes";
        } 
        return "no";
}

int main() {
    fast;
 	int t;
 	cin >> t;
 	while(t--){
        cout << solve() << endl;
 	}   
}