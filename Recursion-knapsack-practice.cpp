#include <bits/stdc++.h>
using namespace std;

// recursion version only
int maxProfit(vector<int>& wt, vector<int> &val, int capacity, int n){
	if(n == 0 || capacity == 0)
		return 0;

	//newar moto
	if(wt[n-1] <= capacity){
		return max(val[n-1] + maxProfit(wt,val, capacity - wt[n-1], n-1)   , // take
				maxProfit(wt, val, capacity, n-1)); // not take
	} 
	// wt beshi nite parbona
	else { // if (wt[n-1] > capacity) 
		return maxProfit(wt, val, capacity, n-1); // not take
	}
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Weight array
    vector<int> wt = {1, 3, 4, 5};  // প্রতিটি আইটেমের weight

    // Value array
    vector<int> val = {15, 20, 30, 50};  // প্রতিটি আইটেমের value

    cout << "MAX profit is : " << maxProfit(wt, val, 10, wt.size());
}   