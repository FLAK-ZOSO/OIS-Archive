/*
 * @Author: Alessandro Farcas (Alenygam)
 * @Date: 2022-04-07
 * @Problem: Festa di laurea
 * @Reference: https://training.olinfo.it/#/task/luiss_laurea/statement
 * @Big-O: O(N)
 */

#include <stdio.h>
#include <string.h>
#include <limits.h>
#define MAXN 107

int N;
int mezzi[4] = {2, 4, 5, 7};
int numeriInit[4];
int prezzi[4];
int costo[MAXN];
int numeri[MAXN][4];

int main() {
	FILE *fr, *fw;
	fr = fopen("input.txt", "r");
	fw = fopen("output.txt", "w");

	fscanf(fr, "%d", &N);

	for (int i = 0; i < 4; i++) {
		fscanf(fr, "%d %d", &numeriInit[i], &prezzi[i]);
	}
	for (int i = 0; i <= 7; i++) {
		costo[i] = 0;
		// copy numeriInit array to numeri[i]
		memcpy(numeri[i], numeriInit, 4 * sizeof(int));
	}
	for (int i = 8; i <= N + 7; i++) {
		costo[i] = INT_MAX;
		for (int j = 0; j < 4; j++) {
			if (numeri[i - mezzi[j]][j] < 1) continue;
			if (costo[i - mezzi[j]] + prezzi[j] < costo[i]) {
				costo[i] = costo[i - mezzi[j]] + prezzi[j];
				// copy numeri[i - mezzi[j]] array to numeri[i]
				memcpy(numeri[i], numeri[i - mezzi[j]], 4 * sizeof(int));
				numeri[i][j]--;
			}

		}
	}
	fprintf(fw, "%d", costo[N + 7]);
}
