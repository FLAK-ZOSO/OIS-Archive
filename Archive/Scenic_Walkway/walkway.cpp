/*
 * @Author: Enea Scaccabarozzi
 * @Date: 2022-03-23
 * @Problem: Scenic Walkway
 * @Reference: https://training.olinfo.it/#/task/ois_walkway/statement
 * @Big-O(N): 
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    // Number of chambers (Vector size), Number of chambers in each spread
    int N, K;

    // Get input
    cin >> N >> K;

    // Vector of chambers
    vector <int> walkway(N);

    // Get input
    for(int i=0; i<N; i++)
        cin >> walkway[i];

    // Sort vector ascending
    sort(walkway.begin(), walkway.end());

    // Store minimun offset of K chamber && Init at starting offset
    int answer = abs(walkway[0] - walkway[K - 1]);

    // Store curretn offset
    int current_offset;

    // Iterate trought chambers
    for (int i=1; i<N-K+1; i++) 
    {
        // Get current offset
        current_offset = abs(walkway[i] - walkway[i + K - 1]);

        // Check if current offset is better
        if(current_offset < answer)
            answer = current_offset;
    }

    // Print answer
    cout << answer << endl;
}
