#include <bits/stdc++.h>
#include <climits>
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

    int MIN = INT_MAX;

    for(int i = 0; i < 10000; i++){
		int B = b + i;
    	if(B == 1){
    		continue;
    	}

    	int count = 0;
    	count += i;
    	int A = a;

    	while(A != 0){
    		A /= B;
    		count++;
    	}

    	if(count > MIN){
    		break;
    	} else {
    		MIN = min(MIN, count);
    	}
    }

    cout << MIN << endl;
}

int main() {
    fast(); 

    int t = 1;
    cin >> t; 

    while (t--) solve();
}
    