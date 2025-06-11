#include<bits/stdc++.h>
using namespace std;

void count(string s){
     int cnt = 1;
     if(s[0] == '1') cnt = 2;

     for(int i = 1; i < s.size(); i++)
     {
          if(s[i] == s[i-1]) cnt++;
          else cnt += 2;
     }

     cout << cnt << endl;
}

int main(){
     int t;
     cin >> t;
     while(t--){
          int n;
          cin >> n;
          string s;
          cin >> s;
           
          int one = -1 , zero = -1;

          for(int i = 0 ; i < n; i++){
               if(s[i] == '1' && one == -1) one = i; 

               else if(s[i] == '0' && one != -1)
               {
                    while(i < n && s[i] == '0') i++;
                    zero = i;
               }

               if(zero != -1) break;
          }

          if(zero == -1 )  count(s);
          else {
               reverse(s.begin() + one  , s.begin() + zero);
               count(s);
          }   
     }
}