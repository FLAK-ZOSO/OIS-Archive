/*
 * @Author: Enea Scaccabarozzi
 * @Date: 2022-03-23
 * @Problem: Compulsive Smartphnes Shopping
 * @Reference: https://training.olinfo.it/#/task/ois_smartphone/statement
 * @Big-O(N): 
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // Number of shops (Vector size)
    int N;
    cin >> N;

    // Vector of shop's prices
    vector <int> prices(N);

    // Current max prices bought
    int current_max = 0;

    // Register money spent
    long long answer = 0;

    // Get input && load answer
    for(int i=0; i<N; i++)
    {
        // Get input 
        cin >> prices[i];

        // Check if current phone is better
        if(prices[i] > current_max)
        {
            answer += prices[i];
            current_max = prices[i];
        }
    }

    // Print answer
    cout << answer << endl;
}
