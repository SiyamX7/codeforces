#include<bits/stdc++.h>
using namespace std;
int main()
 {
     int n;
     cin >> n;
     vector < char > vec(n);
     for(int i = 0;  i < n; i++) cin >> vec[i];

     int l = 0, r = n-1;
     while(r >=l)
     {
         if(vec[l] <= vec[r])
         {
             cout << vec[l];
             l++;

         }
         else
         {
             cout << vec[r];
             r--;
         }
     }
     cout << endl;

 }