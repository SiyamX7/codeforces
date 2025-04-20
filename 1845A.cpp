#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k , x;
        cin >> n >> k >> x;

        if(k > 1 && x > 1){
            cout << "yes" << endl;
            cout << n << endl;
            for(int i = 0; i < n; i++){
                cout << 1 << " \n" [i == n-1];
            }
            continue;
        }
        // no use of 1
        if(k > 1 && n % 2 == 0){
            cout << "yes" << endl;
            cout << n / 2 << endl;
            for(int i = 0; i < n/2; i++){
                cout << 2 << " \n" [i == n/2 - 1];
            }
            continue;
        }

        if(k > 2 && n >= 3){
            cout << "yes" << endl;
            cout << n/2 << endl;
            for(int i = 0; i < n/2 - 1; i++){
                cout << 2 << " ";            
            }
            cout << 3 << endl;
            continue;
        }

        cout << "no" << endl;
    }
}