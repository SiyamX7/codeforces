#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	int b;
	for(int i = 31; i >=0 ; i--)
	{
      if( ((n >> i) & 1)) 
     {
     	b = i;
     	break;
    }
}
   if(b != 31) b++;
   int ans = (1 << b) - 1;
  vector <int > vec(n);
  vec[0] = ans -1 ;
  vec[1] = ans;
  vec[2] = 1;
  vec[3] = 0;
  int cnt = 2;
  for(int i = 4; i < n; i++)
  {
    vec[i] = cnt++;
  }

  for(int i = 0; i < n; i++)
  {
  	cout << vec[i] << " ";
  }
  cout << endl;
 
}
