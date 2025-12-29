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
    int n, k;
    cin >> n >> k;

    vector<int> v(k,0);

    int lcnt = 0;

    if(k % 2 == 1){
        for(int i = 0; i < k; i++){
            v[i] = n;
        }
    } else {
        for(int b = 30; b >= 0; b--){


            if((n >> b) & 1){
                int ban = lcnt;

                for(int i = 0; i < k; i++){
                    if(i != ban) {
                        v[i] += (1 << b);
                    }
                }

                if(lcnt < k) {
                    lcnt++;
                }
            } else {

                int usable = (lcnt / 2) * 2; // jehetu even porjonto chalaite hobe, karon bit 0

                for(int i = 0; i < usable; i++){
                    v[i] += (1 << b);
                }
            }
        }
    }

    print(v);
}

int main() {
    fast(); 

    int t = 1;
    cin >> t; 

    while (t--) solve();
}
    