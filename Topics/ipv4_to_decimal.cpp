#include <bits/stdc++.h>
using namespace std;

string decToBin(string s){
	int n = stoi(s);

	return bitset<8>(n).to_string();
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s;
    cin >> s;

    int l = 0, r = 0;
    vector<string> v;

    string temp = "";

    for(int i = 0; i < s.size(); i++){
    	if(s[i] == '.'){
    		v.push_back(temp);
    		temp.clear();
    	} else {
    		temp += s[i];
    	}
    }

    v.push_back(temp);

    string bit32 = "";
    for(string x : v){
    	bit32 += decToBin(x);
    }

    string decimal = "";
    for(int i = 0; i < 4; i++){
    	string sub = bit32.substr(i*8, 8);
    	
    }

    cout << bit32 << endl;
}   