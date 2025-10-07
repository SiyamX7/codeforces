#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> a = {10, 9, 2, 5, 3, 7, 101, 18};
    int n = a.size();
    
    vector<int> lis;
    for (int x : a) {
        auto it = lower_bound(lis.begin(), lis.end(), x);
        if (it == lis.end()) lis.push_back(x);
        else *it = x;
    }
    
    cout << "LIS length = " << lis.size() << "\n";
    for(int x : lis) cout << x << " ";
}
