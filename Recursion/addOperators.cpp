#include <bits/stdc++.h>
using namespace std;

vector<string> res;

void solve(vector<int> &arr, int curr, int target, int last, int i,  string s){
	int n = arr.size();
	if(i == n){
		if(curr == target){
			res.push_back(s);
		}
		return;
	}

	int num = arr[i];

	solve(arr, curr + num, target, num, i+1, s + " + " + to_string(num));
	solve(arr, curr - num, target, -num, i+1, s + " - " + to_string(num));
	solve(arr, (curr - last) + last * num, target, last * num, i+1, s + " * " + to_string(num));

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    vector<int> arr {1,2,3,4,5,6,7,8,9,10};
    int target = 190;
    solve(arr, arr[0], target, arr[0] , 1, to_string(arr[0]));

    if(!res.size()){
    	cout << "No valid expression." << endl;
    } else {
    	cout << "There are " << res.size() << " valid combinations:" << endl;
    	for(auto s : res){
    		cout << s << " = " << target << endl;
   	 	}
    }
}   