#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    multiset<int> s;
    
    for(int i = 0; i < n; i++){
    	cin >> v[i];
    	if(i < k){
    		s.insert(v[i]);
    	}
    }

    for(int i = 0; i <= n - k; i++){
    	int res = 0;
    	while(s.count(res)){
    		res++;
    	}

    	cout << res << " ";
    	if(i + k < n){
    		s.erase(s.find(v[i])); // deleting the iterator only
    		// s.erase(v[i]) mane hocche oi element shobgula delete kora
    		s.insert(v[i+k]);
    	}
    }
}