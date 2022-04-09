/*
 * @Author: Alessandro Farcas (Alenygam)
 * @Date: 2022-04-09
 * @Problem: Mexican Standoff
 * @Reference: https://training.olinfo.it/#/task/ois_dessert/statement
 * @Big-O: O(N). Way faster than the 5s time limit. Max runtime is 0.5s
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> needed(N);
	// Simple adjacency list
	vector<int> adj[N];
	// special is composed of all i with L equal to zero.
	// The idea is really similar to the interruttori
	// problem on https://territoriali.olinfo.it
	vector<int> special;
	for (int i = 0; i < N; i++) {
		int friends;
		cin >> friends;
		cin >> needed[i];
		if (needed[i] == 0) {
			special.push_back(i);
		}
		for (int j = 0; j < friends; j++) {
			// The graph edges' directions are inverted, otherwise
			// our solution will be wrong.
			int tmp;
			cin >> tmp;
			adj[tmp].push_back(i);
		}
	}

	int visited = 0;
	vector<int> visitedTimes(N, 0);
	// BFS from multiple roots
	deque<int> toVisit;
	for (int spec: special) {
		toVisit.push_back(spec);
	}
	while (toVisit.size() > 0) {
		int node = toVisit.front();
		toVisit.pop_front();
		visited++;
		for (int next: adj[node]) {
			// If already visited useless to visit it again
			if (visitedTimes[next] >= needed[next]) continue;
			// If visitable push to queue
			visitedTimes[next]++;
			if (visitedTimes[next] >= needed[next]) {
				toVisit.push_back(next);
			}
		}
	}

	cout << visited << endl;
}
