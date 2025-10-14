#include <bits/stdc++.h>
using namespace std;

int MEX(vector<int>& v){
	// O(N \log N)
    set <int> s (begin(v), end(v));
    // fast korar jonno just freq array rakhlei hobe

    int res = 0;
    while(s.count(res)) // jodi set e thake, tahole res++
    	res++;

    return res;
}

int Mex(const vector<int> &v){
	int n = v.size();
	vector<int> pres(n+1, 0);

	for(int x : v){
		pres[x]++;
	}

	for(int i = 0; i < n; i++){
		if(!pres[i]){
			return i;
		}
	}

	return n+1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
	vector<int> v {2,1,4,6,4,0,6,3};
	cout << MEX(v) << endl;
	cout << Mex(v) << endl;
}   