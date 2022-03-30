#pragma GCC optimize ("Ofast")
#pragma GCC optimization ("unroll-loops")

#include <stdio.h>
#include <stdbool.h>

// Explanation
//
// 3 in binary: 11
// 11 & 0x01 = 1
//
// 4 in binary: 100
// 100 & 0x01 = 0
//
// This is how I decided to solve this

int main() {
    int N;
    scanf("%d", &N);
    if (N & 0x01) {
        printf("dispari\n");
    } else {
        printf("pari\n");
    }
    return 0;
}
