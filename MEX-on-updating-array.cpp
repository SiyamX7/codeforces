#include <bits/stdc++.h>
#include <initializer_list>
using namespace std;

unordered_map<int,int> freq;
set<int> missing;
vector<int> v;

void initializeMEX(vector<int> const &vec){
	v = vec;
	int n = v.size();
	for(int i = 0; i <= n; i++) {
		missing.insert(i);
	}

	for(int x : v){
		freq[x]++;
		missing.erase(x);
	}
}

int getMEX(){
	return *missing.begin();
}


// old value er freq komano, r jodi freq 0 hoy tahole missing e enlist kora
// new value er freq barano, r missing theke bad dewa
void updateValue(int index, int newValue){
	int oldValue = v[index];
	freq[oldValue]--;
	if(freq[oldValue] == 0){
		missing.insert(oldValue);
	}

	v[index] = newValue;
	freq[newValue]++;
	missing.erase(newValue);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    vector<int> vec = {0,1,3};

    initializeMEX(vec);
    cout << getMEX() << endl;

    updateValue(2,2);
    cout << getMEX() << endl;
}   