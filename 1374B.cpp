#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define pb push_back
#define sort(x) sort(x.begin(), x.end())
#define rsort(x) sort(x.rbegin(), x.rend())
#define vll vector<long long>
#define fast ios::sync_with_stdio(false); cin.tie(nullptr)
#define pop(x) __builtin_popcount(x) // x -> int

int Wassup(){
    int n;
    cin >> n;

    if(n == 1) return 0;
    
    int count = 0;
    while (n != 1) {
        if(n % 6 == 0){
            n /= 6;
            count++;
        } else if(n % 3 == 0) {
            n *= 2;
            count++;
        } else {
            return -1;
        }
    }
    return count;
}

int main() {
    fast;
    
    int t;
    cin >> t;

    while (t--) {
        cout << Wassup() << endl;
    }   
}