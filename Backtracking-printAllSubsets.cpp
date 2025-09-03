#include <bits/stdc++.h>
using namespace std;

void subsets(vector<int>& v, vector<int> &temp, int i) {
	if(i == v.size()){

		if(!temp.size()){
			cout << "{}" << endl;
			return;
		} 

		cout << "{";
		for(int i = 0, n = temp.size(); i < n ; i++){
			cout << temp[i] << ",}"[i == n-1];
		}
		cout << endl;
		return;
	}

	temp.push_back(v[i]);
	subsets(v, temp, i+1);

	temp.pop_back();
	subsets(v, temp, i+1);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    vector<int> v = {1,2,3};
    vector<int> temp;

    subsets(v, temp, 0);
}   