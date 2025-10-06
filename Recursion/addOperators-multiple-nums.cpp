#include <bits/stdc++.h>
using namespace std;

vector<string> res;

void solve(string &digits, int curr, int target, int last, int i,  string s){
	int n = digits.size();
	if(i == n){
		if(curr == target){
			res.push_back(s);
		}
		return;
	}

	for(int j = i; j < n; j++){
		int len = j - i + 1;
		string str = digits.substr(i,len);
		int num = stoll(str);

		if(i == 0){
			solve(digits, num, target, num, j+1,str);
		} else {
			solve(digits, curr + num, target, num, j+1, s + " + " + str);
			solve(digits, curr - num, target, -num, j+1, s + " - " + str);
			solve(digits, (curr - last) + last * num, target, last * num, j+1, s + " * " + str);
		}
	}
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string digits = "123456789";
    int target = 190;
    solve(digits, 0, target, 0 , 0, "");

    if(!res.size()){
    	cout << "No valid expression." << endl;
    } else {
    	cout << "There are " << res.size() << " valid combinations:" << endl;
    	for(auto s : res){
    		cout << s << " = " << target << endl;
   	 	}
    }
}   