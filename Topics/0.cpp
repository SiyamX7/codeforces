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
   ll a;
   cin >> a;

   int count = 0;
   bool flag = false;
   for(ll i = 1; i * i <= a; i++){
   		if(a % i == 0){
   			count++;
   			if(i * i == a) flag = true;
   		}
   }

   if(!flag){
   		cout << 2 * count << endl;
   } else {
   		cout << 2 * count - 1 << endl;
   }

}

int main() {
    fast(); 

    int t = 1;
    cin >> t; 

    while (t--) solve();
}
    