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
    string s;
    cin >> s;
    int n = s.size();

    if(s.size() == 1){
        cout << 1 << endl;
        return;
    }

    if(s[0] == '>' && s[n-1] == '<'){
        cout << -1 << endl;
        return;
    }

    for(int i = 0; i+1 < n; i++){
        if(s[i] == '*' && s[i+1] == '<'){
            cout << -1 << endl;
            return;
        }

        if(s[i] == '*' && s[i+1] == '*'){
            cout << -1 << endl;
            return;
        }

        if(s[i] == '>' && s[i+1] == '*'){
            cout << -1 << endl;
            return;
        }

        if(s[i] == '>' && s[i+1] == '<'){
            cout << -1 << endl;
            return;
        }

    }

    int l = 0, r = n-1,rc = 0;

    if(s[0] == '<'){
        while(l < n && (s[l] == '<' || s[l] == '*')) l++;
    }

    if(s[n-1] == '>'){
        while(r >= 0 && (s[r] == '>' || s[r] == '*')) r--, rc++;
    }

    cout << max(l, rc) << endl;
}

int main() {
    fast(); 

    int t = 1;
    cin >> t; 

    while (t--) solve();
}
    