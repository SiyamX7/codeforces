#include <bits/stdc++.h>
using namespace std;

// amader function ta maximum profit return kortese.
int knapsack(int n, int W, vector<int>& wt, vector<int>& val) {
    // base case
    if(n == 0 || W == 0) return 0;

    if(wt[n-1] <= W) {
        // দুইটা চয়েস: নেই অথবা না নেই
        return max(
            val[n-1] + knapsack(n-1, W - wt[n-1], wt, val), // 1. নেই
            knapsack(n-1, W, wt, val)                       // 2. না নেই
        );
    } else {
        // ওজন বেশি হয়ে গেলে নিতে পারবো না
        return knapsack(n-1, W, wt, val);
    }
}

/*
	jokhon amra ekta mal nei (1)-->
	tokhon amra oi maler value + aro je mal gula ache shei mal gular max profit koto 
	hote pare ta jog kori

	na nile (2)-->
	ei mal chara baki maler max profit koto hobe ta hisheb kore dekhbo
*/

int main() {
    int n = 3, W = 5;
    vector<int> wt = {3, 2, 4};
    vector<int> val = {60, 100, 120};

    cout << "Maximum value = " << knapsack(n, W, wt, val) << endl;
}