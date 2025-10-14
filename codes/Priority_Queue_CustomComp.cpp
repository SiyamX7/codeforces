#include <bits/stdc++.h>
#include <functional>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

struct comp {
    bool operator()(const pair<int,int> &a, const pair<int,int> &b){
        return a.second > b.second;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    vector<int> v = {4,3,2,5,7,3};
    // priority_queue<int, vector<int>, less<int>> pq(v.begin(), v.end());

    vector<pair<int,int>> pp = {{1,2}, {4,3}, {4,2}, {2,7}};
    priority_queue<pair<int,int>, vector<pair<int,int>>, comp> pq(pp.begin(), pp.end());
    while(!pq.empty()){
        cout << pq.top().first << " " << pq.top().second << endl;
        pq.pop();
    } 
}
