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
    ll a, b;
    cin >> a >> b;

    if(a > b) swap(a,b);

    ll count = 0;

    while((1 << count) <= a) count++;

    if(b > (1 << (count+1))) b = (1 << (count+1));
    // cout << "B " << b << endl; 

    ll aev = 0, aodd = 0, bev = 0, bodd = 0;

    ll tempa = a;
    for(int i = 0; i < 29; i+=2){
    	ll x = (1 << i);
    	if(x <= tempa) {
    		tempa -= x;
    		aodd++;
    	} else {
    		break;
    	}
    }

    tempa = a;
    for(int i = 1; i < 29; i+=2){
    	ll x = (1 << i);
    	if(x <= tempa) {
    		tempa -= x;
    		aev++;
    	} else {
    		break;
    	}
    }

    ll tempb = b;
    for(int i = 0; i < 29; i+=2){
    	ll x = (1 << i);
    	if(x <= tempb) {
    		tempb -= x;
    		bodd++;
    	} else {
    		break;
    	}
    }

    tempb = b;
    for(int i = 1; i < 29; i+=2){
    	ll x = (1 << i);
    	if(x <= tempb) {
    		tempb -= x;
    		bev++;
    	} else {
    		break;
    	}
    }

    cout << max(aev+bodd, aodd + bev) << endl;
}

int main() {
    fast(); 

    int t = 1;
    cin >> t; 

    while (t--) solve();
}
    