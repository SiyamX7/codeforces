#include<bits/stdc++.h>
using namespace std;
int main(){
     int t;
     cin >> t;
     while(t--){
          vector<int> v(3);
          for(int &val : v) cin >> val;
          
          sort(v.begin(), v.end());
          if(v[0] + v[1] == v[2]) {
               cout << "yes" << endl;
          } else {
               cout << "no" << endl;
          }
     }
}