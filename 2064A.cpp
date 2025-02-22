#include <bits/stdc++.h>
using namespace std;

template <typename T>
void print(const vector<T>& vec) {
    for (const auto& val : vec) {
        cout << val << " ";
    }
    cout << endl;
}
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#define ll long long                
#define vi vector<int> 
#define vb vector<bool>             
#define vll vector<long long>       
#define pii pair<int, int>          
#define pll pair<long long, long long> 
#define pb push_back                
#define mp make_pair                
#define all(v) v.begin(), v.end()  
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x.size())      
#define ff first                     
#define ss second                    
#define endl '\n'  
#define debug(x) cerr << #x << " = " << x << endl                 

const int MOD = 1e9 + 7;            
const ll INF = 1e18;                



int main() {
    fast; 
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        int count = 0;
        for(int i = 1; i < n; i++){
            if(s[i] != s[i-1]){
                count++;
            }
        }
        if(s[0] == '1') cout << count + 1 << endl;
        else cout << count << endl;
    }
    return 0;
} 