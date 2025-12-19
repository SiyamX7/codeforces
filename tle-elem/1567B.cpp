#include <bits/stdc++.h>
using namespace std;

#define ll  long long              
#define pb  push_back
#define eb  emplace_back                                 
#define bug(x) cerr << #x << " = " << x << endl                 
 
void fast() {ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
template <typename T>
void print(const vector<T>& vec) {for (const auto& val : vec) {cout << val << " ";}cout << endl;}

void solve(){
    int a, b; 
    cin >> a >> b;

    int XOR = 0;
    int k = a-1;

    if(k % 4 == 0){
    	XOR = k;
    } else if (k % 4 == 1){
    	XOR = 1;
    } else if(k % 4 == 2){
    	XOR = k + 1;
    } else {
    	XOR = 0;
    }

    if(XOR == b){
    	cout << a << endl;
    } else if((XOR ^ b) == a){
    	cout << a + 2 << endl;
    } else {
    	cout << a + 1 << endl;
    }
}

int main() {
    fast(); 

    int t = 1;
    cin >> t; 

    while (t--) solve();
}
    