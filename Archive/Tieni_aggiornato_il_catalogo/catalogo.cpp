/*
 * @Author: Alessandro Farcas (Alenygam)
 * @Date: 2022-04-06
 * @Problem: Tieni aggiornato il catalogo
 * @Reference: https://training.olinfo.it/#/task/catalogo/statement
 * @Big-O: O(1) best case (but rehashing is a thing :crying:)
 */

#include <unordered_map>

std::unordered_map<long long int, int> mappa;

void aggiungi(long long int id) {
	if (mappa.find(id) == mappa.end()) {
		mappa[id] = 0;
	}
	mappa[id]++;
}

void togli(long long int id) {
	mappa[id]--;
}

int conta(long long int id) {
	return mappa[id];
}
