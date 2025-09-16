#include <bits/stdc++.h>
using namespace std;

set<int> missing;
unordered_map<int,int> freq;

int mex(){
	return *missing.begin();
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> v;
    
    int n, k;
    cin >> n >> k;

    for(int i = 0; i <= n; i++){
    	missing.insert(i);
    }

    for(int i = 0; i < k; i++){
    	int x; cin >> x;
    	v.push_back(x);
    	freq[x]++;
    	missing.erase(x);
    }

    cout << mex() << " ";

    for(int i = k; i < n; i++){
    	int x; cin >> x; 
    	v.push_back(x);
    }

    for(int i = k; i < n; i++){
    	freq[v[i-k]]--;
    	if(freq[v[i-k]] == 0) {
    		missing.insert(v[i-k]);
    	}

    	freq[v[i]]++;
    	missing.erase(v[i]);
    	
    	cout << mex() << " ";
    }
}   