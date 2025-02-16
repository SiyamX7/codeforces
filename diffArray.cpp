#include <bits/stdc++.h>
using namespace std;

vector<int> diffArrayCreate(vector<int> v){
    int n = v.size();

    vector<int> diff(n+1, 0);
    diff[0] = v[0];

    for(int i = 1; i < n; i++){
        diff[i] = v[i] - v[i-1];
    }

    return diff;
}

void print(vector<int>& v){
    for(auto val : v) cout << val << " ";
    cout << endl;
}

int main(){
    vector<int> v = {10,5,20,40};

    vector<int> d = diffArrayCreate(v);
    print(d);
    
}