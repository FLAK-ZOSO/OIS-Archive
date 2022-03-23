/*
 * @Author: Enea Scaccabarozzi
 * @Date: 2022-03-23
 * @Problem: Somme Costose
 * @Reference: https://training.olinfo.it/#/task/gator_somme/statement
 * @Big-O(N): 
*/

#include <iostream>
#include <queue>
using namespace std;

int main()
{
    // Read/write from files
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    // Number of numbers :) (Queue size)
    int N;
    cin >> N;

    // Priority queue to store input numbers from min to max
    priority_queue <int> _input;

    // Temp var in order to insert in queue
    int dummy;

    // Get input
    for(int i=0; i<N; i++)
    {
        cin >> dummy;
        _input.push(-dummy);
    }

    // Store minimun cost
    int answer = 0;

    // Store current sum, best at that moment
    int current_sum;

    // Iterate trought queue
    while(_input.size()>1)
    {
        // First number to be summed
        current_sum = _input.top();
        _input.pop();

        // Second number to be summed
        current_sum += _input.top();
        _input.pop();

        // Add new number
        _input.push(current_sum);

        // Update current cost
        answer += current_sum;
    }

    // Print answer
    cout << -answer << endl;

}
