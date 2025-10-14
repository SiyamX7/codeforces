#include <bits/stdc++.h>
using namespace std;

int main() {
    int A[7][7] = {
        {0,  0,  0,  0,  0,  0,  0},
        {0, -3,  2,  5, -1,  4, -2},
        {0,  1, -5,  3,  0, -4,  2},
        {0,  4,  1, -2,  5, -3,  0},
        {0, -1,  3,  2, -5,  1,  4},
        {0,  2, -4,  0,  3, -1, -5},
        {0,  5, -2,  1, -3,  4,  0}
    };

    // for (int i = 0; i < 7; i++) {
    //     for (int j = 0; j < 7; j++) {
    //         cout << setw(2) << A[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    //query sum from (a,b) to (c,d) is,
    int a = 3, b = 3, c = 6, d = 6;

    long sum = 0;
    for(int i = a; i <= c; i++){
        for(int j = b; j <= d; j++){
            sum += A[i][j];
        }
    }

    //Now building the prefix sum array;
    int P[7][7];

    for(int i = 1; i < 7; i++){
        for(int j = 1; j < 7; j++){
            P[i][j] = A[i][j]
                    + P[i-1][j]
                    + P[i][j-1]
                    - P[i-1][j-1];
        }
    }

    cout << sum << endl;
}