#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n , m , l , r;
     cin >> n >> m >> l >> r;
     int k = m ;
     int left = 0, right = 0;
     while(k--)
     {
        if(right < r)
        {
            right++;
        }
        else if(l < left) 
        {
            left--;
        }

     }
     cout << left << " " << right << "\n"; 

}
   
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
}