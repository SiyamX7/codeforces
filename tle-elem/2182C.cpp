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
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n);

    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    for(int i = 0; i < n; i++) cin >> c[i];

    int count = 0;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			for(int k = 0; k < n; k++){
				bool gg = false;

				for(int l = 0; l < n; l++){

					int x = a[(i+l) % n];
					int y = b[(j+l) % n];
					int z = c[(k+l) % n];

					if(!(x < y && y < z)){
						gg = true;
						break;
					}
					
				}

				if(!gg) count++;
			}
		}
	}

	cout << count << endl;
}

int main() {
    fast(); 

    int t = 1;
    cin >> t; 

    while (t--) solve();
}
    