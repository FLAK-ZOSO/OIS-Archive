/*
 * @Author: Alessandro Farcas (Alenygam)
 * @Date: 2022-04-06
 * @Problem: Numero della cabala
 * @Reference: https://training.olinfo.it/#/task/ois_cabala/statement
 * @Big-O: O(2^N log N) slow af but it works
 */

#include <limits.h>
#include <stdio.h>

long long maxMod = -1;

// Fast exponentiation O(log exp)
long long power(int base, int exp) {
	if (exp == 0) return 1;
	long long r = power(base, exp / 2);
	r = r * r;
	if (exp % 2 == 1) r = base * r;
	return r;
}

// We recurse through every single possible digit to find the one with the highest 
// number after modulo operation
void recursive(int N, int n, long long M, long long calculated, int lastDigit) {
	if (n == N) return;
	for (int i = 3; i <= 9; i+=3) {
		if (i == lastDigit) continue;
		long long newCalc = calculated + (i * power(10, n));
		if (newCalc % M > maxMod) maxMod = newCalc % M;
		recursive(N, n + 1, M, newCalc, i);
	}

}

long long occulta(int N, long long M) {
	recursive(N, 0, M, 0, 0);
	return maxMod;
}

int main() {
	int T;
	FILE *fr, *fw;
	fr = fopen("input.txt", "r");
	fw = fopen("output.txt", "w");

	// Read each testcase
	fscanf(fr, "%d", &T);
	for (int i = 0; i < T; i++) {
		maxMod = -1;
		int N;
		long long M;
		fscanf(fr, "%d %lld", &N, &M);
		fprintf(fw, "%lld ", occulta(N, M));
	}
	return 0;
}
