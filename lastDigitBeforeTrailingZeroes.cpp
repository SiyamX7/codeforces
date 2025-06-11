#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll MAX = 1e6+1;
vector<int> v(MAX);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	
	v[1] = 1;
    for(int i = 2; i <= MAX; i++){
    	v[i] = v[i-1] * i;
    	while(v[i] % 10 == 0){
    		v[i] /= 10;
    	}
    	v[i] %= 10;
    }

    while(1){
    	int n;
    	cin >> n;
    	if(n > 0){
    		cout << n << " " << v[n] << endl;
    	} else {
    		break;
    	}
    }
}