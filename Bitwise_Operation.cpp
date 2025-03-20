#include <bits/stdc++.h>
using namespace std;

void OR(){
	int a = 5, b = 3;
	int res = a | b;
	cout << res << endl;
}

void AND(){
	int a = 5, b = 3;
	int res = a & b;
	cout << res << endl;
}

void XOR(){
	int a = 5, b = 3;
	int res = a ^ b;
	cout << res << endl;
}

void NOT(){
	int a = 5;
	int res = ~a;
	cout << res << endl;
}

void LEFT_SHIFT(){
	int a = 5;
	int res = a << 1;
	cout << res << endl;
}

void RIGHT_SHIFT(){
	int a = 5;
	int res = a >> 1;
	cout << res << endl;
}

void SWAP(){
	int a = 3;
	int b = 4;

	a = a ^ b;
	b = a ^ b;
	a = a ^ b;

	cout << a << " " << b << endl;
}

void NonRepeatingNumber(){
	vector<int> v = {1,1,2,2,3,4,4,5,5,5,5}; //appears only once

	int res = 0;

	for(int i : v){
		res ^= i;
	}

	cout << res << endl;
}

void isPowerOfTwo(){
	int n = 16;
	int res = n & (n - 1);

	if(res == 0) {
		cout << "isPowerOfTwo" << endl;
	} else {
		cout << "NotPowerOfTwo" << endl;
	}
}

void countSetBits() {
	int n = 7;
    cout << __builtin_popcount(n) << endl;

    //or use Brian Kerninghan's Algorithm (faster)
    int count = 0;
    while (n) {
        n = n & (n - 1); // Removes the rightmost set bit
        count++;
    }
    cout << count << endl;
}

void rightmostSetBit() {
	int n = 6;
    cout << (n & -n) << endl;
}

int xorFrom1ToN() {
	int n = 678;
    if (n % 4 == 0) return n;
    if (n % 4 == 1) return 1;
    if (n % 4 == 2) return n + 1;
    return 0;
}


int main(){
	OR();
	AND();
	XOR();
	NOT();
	LEFT_SHIFT();
	RIGHT_SHIFT();
	SWAP();
	NonRepeatingNumber();
	isPowerOfTwo();
	countSetBits();
	rightmostSetBit();
	cout << xorFrom1ToN() << endl;
}