#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
vector<int> tree[N];
int sub[N];

int kamla(int curr){
	int count = 0;
	for(int x : tree[curr]){
		if(!sub[x])
		count += 1 + kamla(x);
	}
	sub[curr] = count;
	return count;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
   
   	int n;
   	cin >> n;

   	for(int i = 2; i <= n; i++){
   		int x; 
   		cin >> x;
   		tree[x].push_back(i);
   	}

   	kamla(1);
   	for(int i = 1; i <= n; i++){
   		cout << sub[i] << endl;
   	}
}