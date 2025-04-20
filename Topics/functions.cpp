#include <algorithm>
#include <bits/stdc++.h>
#include <numeric>
#include <random>
using namespace std;                   

int main() {
	int n = 10;
	//vector er value "x" theke shuru korte iota(begin, end, x) use kora jay
	vector<int> v(n);     
	iota(v.begin(), v.end(), 1);


	//					***RANDOM NUMBERS***

	//			C-style Random number generator, uses <cstdlib>
	srand(time(0)); // Seed for randomness, seed na korle abar same ashte pare
    cout << "Random number: " << rand() << endl;
    cout << "Random number (0-99): " << rand() % 100 << endl;

    //			C++ style, more modern, fast. C++ 11 or more <random>

    //			Mersenne Twister random number generator
	
	cout << mt19937(time(0)) << endl; // this is wrong X
	// mt19937 ekta object, not a single number

	mt19937 generator(time(0));	
	cout << generator() << endl; // evabe ekta sigle integer number pabo


    //		    Shuffling a vector (Useful in randomized algorithms)

    vector<int> vv = {1, 2, 3, 4, 5};
    shuffle(vv.begin(), vv.end(), mt19937(time(0)));
    cout << "Shuffled vector: ";
    for (int num : v) cout << num << " ";
    cout << "\n";

}