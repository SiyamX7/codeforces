#include <algorithm>
#include <bits/stdc++.h>
#include <iterator>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    vector<int> a = {10, 9, 2, 5, 3, 7, 101, 18};
    int n = a.size();

    vector<int> dp(n, 1);
    vector<int> parent(n,-1);

    int len = 1;
    int lastIndex = 0;

    for(int i = 0; i < n; i++){
    	for(int j = 0; j < i; j++){
    		if(a[j] < a[i]){
    			if(1 + dp[j] > dp[i]){
    				dp[i] = 1 + dp[j];
    				parent[i] = j;
    			}
    		}
    	}

    	if(dp[i] > len){
    		len = dp[i];
    		lastIndex = i;
    	}
    }

    vector<int> lis;
    while (lastIndex != -1) {
    	lis.push_back(a[lastIndex]);
    	lastIndex = parent[lastIndex];
    }
    reverse(begin(lis), end(lis));

    cout << lis.size() << endl;
    for(int x : lis){
    	cout << x << " ";
    }
}   