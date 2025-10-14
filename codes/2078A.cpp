#include <bits/stdc++.h>
#include <numeric>
using namespace std;

string gg(){
	int n, x;
	cin >> n >> x;

	vector<int> v(n);
	for(int &i : v) cin >> i;

	for(int i = 1; i <= n; i++){
		if(n % i == 0){
			int left = 0, right = i;
			int avg = 0;
			while(right <= n){
				int sum = accumulate(v.begin() + left, v.begin() + right, 0);
				avg += (sum / i);
				left += i;
				right += i;
			}
			if(avg == x) return "yes";
		}
	}
	return "no";
}

int main(){
	int t;
	cin >> t;
	while(t--){
		cout << gg() << endl;
	}
}