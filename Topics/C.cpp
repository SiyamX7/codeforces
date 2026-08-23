#include<bits/stdc++.h>
#include <ios>
using namespace std;
#define ll long long
long long n = 1e+7;
     vector < long > vec(n+1);
     vector < long > pre(n+2,0);
void built()
{
	
     
     ll cnt = 0;
     for(ll i = 0 ; i <= n; i++)
     {
        if((1 << cnt) < i) 
        {
           pre[i+1] = (pre[i] + cnt) % n;
              
        }
        else
        {
        	cnt++;
        	pre[i+1] = (pre[i] + cnt)%n;

        }
     }

	
}
void solve()
{
   for(int i = 0; i <= 10; i++)
   {
   	cout << pre[i] << " ";
   }
   cout << endl;
}
int main()
{

	int t=1;
	built();
	solve();
	
}