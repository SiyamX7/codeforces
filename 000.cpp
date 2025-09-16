#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
void solveb()
{
  int n;
  cin >> n;
  vector < int > vec(n);
  vector < int > pos;
  vector < bool > visited(n + 1, false);
  for(int i = 0; i < n; i++)
  {
    cin >> vec[i];
     visited[vec[i]] = true;
  }
 for(int i = 1; i <= n; i++ )
 {
    if(!visited[i])
    {
        pos.push_back(i);
    }
 }
 sort(pos.begin() , pos.end());
 
 
 for(int i = 0; i < n; i++)
 {
    if(vec[i] == 0)
    {
      vec[i] = pos[pos.size() - 1];
      pos.pop_back();
    }
 }
 
int left = 0;
int right = n - 1;
bool left_flag = false;
bool right_flag = false;
while(right > left)
{
  if(left_flag == false && vec[left] == left + 1)
  {
    left++;
  }
  else
  {
    left_flag = true;
  }
 
  if(right_flag == false && vec[right] == right+ 1)
  {
    right--;
  }
  else
  {
    right_flag = true;
  }
 
  if(left_flag == true && right_flag==true) break;
}
if(right > left) cout << right - left + 1 << "\n";
else cout << "0\n";
 
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solveb();
    }
    return 0;
}