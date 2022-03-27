/*
 * @Author: Enea Scaccabarozzi
 * @Date: 2022-03-26
 * @Problem: Mozzarelle di Bufala
 * @Reference: https://training.olinfo.it/#/task/ois_bilancio/statement
 * @Big-O: O(N)
 */

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // Read/write from files
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    // Number of balance's digits (input dimension), Number of erasable digits
    int N, K;

    // Get input
    cin >> N >> K;

    // Vector of balance digits
    vector<int> _input(N);

    // Vector of answer's digits (balance after erasing K digit)
    vector<int> answer(N - K);

    // Get input
    for (int i = 0; i < N; i++)
        cin >> _input[i];

    // Answer lenght
    int len = N - K;

    // Init operations
    answer[0] = _input[0];

    // Store last digit taken from original balance (_input)
    int last_digit = 0;

    // Iterator on original balance
    int i = 1;

    // Iterate trought original balance
    while (i < N)
    {
        // Check if current digit of balance is smaller than last digit taken 
        while (last_digit >= 0 && K > 0 && _input[i] < answer[last_digit])
        {
            // If is smaller (and in buonds) decrease K and last digit
            last_digit--;
            K--;
        }
        
        // Check if answer isn't already full
        if (last_digit < len - 1)
        {
            // If so take current last digit in the answer
            last_digit++;
            answer[last_digit] = _input[i];
        }
        // If not decrease K 
        else
        {
            K--;
        }

        // Continue cycle
        i++;
    }


    // Print answer
    for (i = 0; i < answer.size(); i++)
        cout << answer[i] << " ";
    cout << endl;
}
