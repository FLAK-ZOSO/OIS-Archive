#include <bits/stdc++.h>
#define NMAX 10000

using namespace std;
int N;
int panini[NMAX];
int soluzioni[NMAX];

int main() {
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	// Prendiamo i panini e li mettiamo nell'array panini
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> panini[i];
	}
	// Scorriamo l'array al contrario.
	for (int i = N - 1; i >= 0; i--) {
		int val = 0;
		// Vediamo se tra le soluzioni già trovate vi é giá
		// una soluzione con un panino di peso minore.
		// Se è presente prendiamo il massimo tra le altre
		// soluzioni che rispettano questo criterio.
		for (int j = i; j < N; j++) {
			if (panini[j] < panini[i]) {
				val = max(val, soluzioni[j]);
			}
		}
		soluzioni[i] = val + 1;
	}
	int massimo = soluzioni[0];
	for (int i = 1; i < N; i++) {
		// Stampiamo la soluzione di valore massimo
		massimo = max(soluzioni[i], massimo);
	}
	cout << massimo << endl;
}
