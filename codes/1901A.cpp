#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
using namespace std;                   

int main() {
    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;
        string s;
        cin >> s;
        
        int dot = 0;

        for(int i = 0; i < n; i++) {
            if(s[i] == '.') dot++; 
        }
        bool flag = false;

        for(int i = 0; i < n-2; i++){
            if(s.substr(i,3) == "..."){
                flag = true;
                break;
            }
        }

        if(flag) cout << 2 << endl;
        else cout << dot << endl;
    }
}