/*
 * @Author: Enea Scaccabarozzi
 * @Date: 2022-03-22
 * @Problem: Ropes Escape
 * @Reference: https://training.olinfo.it/#/task/ois_ropes/statement
 * @Big-O: O(N)
 */

#include <bits/stdc++.h>
using namespace std;

int main()
{
    //  uncomment the following lines if you want to read/write from files
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    // Vector dimension
    int N; 
    cin >> N;

    // Vector of inputs
    vector <int> connected_to(N), time_required(N);

    // Max node with childs
    int max_parent_node = 0;

    // Get input
    for (int i = 0; i < N; i++)
    {
        cin >> connected_to[i];
        max_parent_node = max(max_parent_node, connected_to[i]);
    }
    for (int i = 0; i < N; i++)
        cin >> time_required[i];

    // Save maximum time required at each node
    vector<int> maximum(max_parent_node + 1, 0);

    // Init total time
    int total = 0;
    for (int i = 0; i < N; i++)
    {
        total += time_required[i];
        maximum[connected_to[i]] = max(maximum[connected_to[i]], time_required[i]);
    }

    // Subtract time savable from total time required
    total -= accumulate(maximum.begin(), maximum.end(), 0);

    // Print Answer
    cout << total << endl;
    return 0;
}
