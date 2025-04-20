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

string valid(){
	int a, b, c;
	cin >> a >> b >> c;

	int A = b - (c - b);
	if(A >= a and A % a == 0 and A != 0){
		return "yes";
	}

	int B = a + (c - a) / 2; 
	if(B >= b and (c - a) % 2 == 0 and B % b == 0 and B != 0){
		return "yes";
	}

	int C = b + (b - a);
	if(C >= c and C % c == 0 and C != 0){
		return "yes";
	}

	return "no";
}

int main() {
    fast;
 	int t;
 	cin >> t;
 	while(t--){
 		cout << valid() << endl;
 	}   
}