#include <bits/stdc++.h>
#include <vector>
using namespace std;

void print1toN(int n){
	if(n == 0) return;
	print1toN(n-1);
	cout << n << " ";
}

void printNto1(int n){
	if(n == 0) return;
	cout << n << " ";
	printNto1(n-1);
}

int sum(int n){
	if(n == 0) return 0;
	return  n + sum(n-1);
}

int fact(int n){
	if(n <= 1) return 1;
	return n * fact(n-1);
}

int dp[1000];
int fib(int n){
	if(n <= 2) return 1;
	if(dp[n] != 0) return dp[n];
	return dp[n] = fib(n-1) + fib(n-2);
}

void revArray(vector<int> &a, int left, int right){
	if(left >= right) return;
	swap(a[left], a[right]);
	revArray(a, left+1, right-1);
}

bool isPalindrome(string &s, int start, int end){
	if(start >= end) return true;
	if(s[start] != s[end]) return false;
	return isPalindrome(s, start+1, end-1);
}

vector<int> stairDP(1000,-1);
int stair(int n){
	if(n < 0) return 0;
	if(n == 0) return 1;

	if(stairDP[n] != -1) return stairDP[n];
	return stairDP[n] = stair(n-1) + stair(n-2);
}

// array is sorted in descending order
int Bin(vector<int> &a, int left, int right, int target){
	if(left > right) return -1;
	int mid = left + (right - left) / 2;

	if(a[mid] == target) return mid;
	return a[mid] > target ? Bin(a, mid+1, right, target) : Bin(a, left, mid-1, target);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	
    print1toN(5);
    cout << endl;
    printNto1(5);
    cout << endl;
    cout << sum(5) << endl;
    cout << fact(5) << endl;
    cout << fib(5) << endl;
   	string s = "madam";
   	cout << isPalindrome(s, 0, s.size()-1) << endl;
   	vector<int> a = {1,2,3,4,5};
   	revArray(a, 0, a.size()-1);
   	for(int i : a) cout << i << " "; 
   	cout << endl;

   cout << stair(4) << endl;
   cout << Bin(a, 0,a.size()-1, 3) << endl;
}