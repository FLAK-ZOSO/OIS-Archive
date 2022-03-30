#include <bits/stdc++.h>
// Better optimizations :gigachad:
// Be really careful if you're using ofast, since it
// is really unstable with floating point numbers.
// Since we're not using floating point numbers
// we can use it without real side effects.
#pragma GCC optimize ("Ofast")
#pragma GCC optimization ("unroll-loops")

#define MAX_GRADE 10

using namespace std;

// Really easy implementation of counting sort.
// If you ever programmed you should figure this
// out by yourself.
void countingSort(int N, int array[]) {
	int tmp[MAX_GRADE] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	for (int i = 0; i < N; i++) {
		tmp[array[i] - 1]++;
	}
	int index = 0;
	for (int i = 0; i < MAX_GRADE; i++) {
		for (int j = 0; j < tmp[i]; j++) {
			// We modify the array in place
			// to use less memory.
			array[index] = i + 1;
			index++;
		}
	}
}

bool associabili(int N, int v1[], int v2[]) {
	// Using counting sort instead of normal
	// stl sort since it is faster with lower
	// of v1 and v2
	// Also normal sort doesn't allow us to complete
	// the exercise with 100/100
	countingSort(N, v1);
	countingSort(N, v2);
	for (int i = 0; i < N; i++) {
		if (v1[i] >= v2[i]) {
			return false;
		}
	}
	return true;
}
