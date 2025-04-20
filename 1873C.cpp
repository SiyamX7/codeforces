#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define vb vector<bool>
#define fast ios::sync_with_stdio(0); cin.tie(0);

using namespace std;                   

int score[10][10] = {
	{1,1,1,1,1,1,1,1,1,1},
	{1,2,2,2,2,2,2,2,2,1},
	{1,2,3,3,3,3,3,3,2,1},
	{1,2,3,4,4,4,4,3,2,1},
	{1,2,3,4,5,5,4,3,2,1},
	{1,2,3,4,5,5,4,3,2,1},
	{1,2,3,4,4,4,4,3,2,1},
	{1,2,3,3,3,3,3,3,2,1},
	{1,2,2,2,2,2,2,2,2,1},
	{1,1,1,1,1,1,1,1,1,1}
};

int main() {
    fast;
    int t;
    cin >> t;
    while(t--){
    	int ans = 0;

    	for(int i = 0; i < 10; i++){
    		for(int j = 0; j < 10; j++){
    			char c;
    			cin >> c;
    			if(c == 'X'){
    				ans += score[i][j];
    			}
    		}
    	}

    	cout << ans << endl;

    }
 	   
}