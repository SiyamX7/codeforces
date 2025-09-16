#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    vector<int> v {5,12,1,6};
    int n = v.size();
    int sum = 0;

    for(int &x : v) sum += x;

    if(sum % 2 == 1) {
    	cout << "Impossible" << endl;
    	return 0;
    }

    int target = sum / 2;
    vector<bool> dp(target+1, false);

    dp[0] = true;

    for(int i = 0; i < n; i++){
        if(v[i] > target) continue;
        for(int j = target; j >= v[i]; j--){
            dp[j] = dp[j] || dp[j - v[i]];
        }
    }    

    // amader else condition ta lagtesena, karon ekhane
    // j >= v[i] jeta else condition auto handle kortese

    if(dp[target]) {
    	cout << "Possible" << endl;
    } else {
    	cout << "Impossible" << endl;
    }
}   