#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    vector<int> v = {2 ,1 };

    int n = v.size();
    vector<int> leftMax(n), rightMin(n);

    leftMax[0] = v[0];

    for(int i = 1; i < n; i++){
    	leftMax[i] = max(leftMax[i-1], v[i]);
    }

    rightMin[n-1] = v[n-1];

    for(int i = n-2; i >= 0; i--){
    	rightMin[i] = min(rightMin[i+1], v[i]);
    }

    for(int i = 0; i < n; i++){
    	bool left = (i == 0) || (leftMax[i-1] < v[i]);
    	bool right = (i == n-1) || (rightMin[i+1] > v[i]);

    	if(left && right){
    		cout << i+1 << endl;
    		break;
    	}
    }
}   