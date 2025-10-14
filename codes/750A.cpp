#include <bits/stdc++.h>
using namespace std;                   
#define vi std::vector<int>
int main() {

		int n, k;
        cin >> n >> k;
	    vi pref(11,0);
        for(int i = 1; i < 11; i++){
        	pref[i] = 5 * i + pref[i-1];
        }

        int val = 240 - k;
        int right = 10, left = 0, mid;

        while(right - left > 1){
        	mid = (right + left) / 2;
        	if(pref[mid] > val){
        		right = mid;
        	} else {
        		left = mid;
        	}
        }
        // cout << left << " " << right << endl;
        cout << min(left, n) << endl;
}