/*
 * @Author: Alessandro Farcas (Alenygam)
 * @Date: 2022-04-06
 * @Problem: Trova il Massimo
 * @Reference: https://training.olinfo.it/#/task/massimo/statement
 * @Big-O: O(N)
 */

int trova_massimo(int N, int V[]) {
	int maximum = -1000;
	for (int i = 0; i < N; i++) {
		maximum = V[i] > maximum ? V[i] : maximum;
	}
	return maximum;
}
