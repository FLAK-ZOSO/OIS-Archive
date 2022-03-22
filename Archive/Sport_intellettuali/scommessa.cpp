/*
 * @Author: Enea Scaccabarozzi
 * @Date: 2022-03-22
 * @Problem: Sport Intellettuali
 * @Reference: https://training.olinfo.it/#/task/scommessa/statement
 * @Big-O: O(N^2)
 */

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // Read/write from files
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    // Vector size (Number of cards)
    int N;

    // Vector of cards
    vector<int> _input_vett;

    // Vector with every possibile last card
    vector<int> answer;

    // Get input
    cin >> N;
    _input_vett.resize(N);
    for (int i = 0; i < N; i++)
        cin >> _input_vett[i];

    // Is removable all dx cards next to current checked card
    bool dx;

    // Is removable all sx cards next to current checked card
    bool sx;

    // Number of even and odd cards in each partition of the cards vector
    int even;
    int odd;

    // Iterate trought cards vector
    for (int i = 0; i < N; i++)
    {
        // At start solution is possible
        dx = sx = true;

        // Init counter to 0
        even = odd = 0;
        // Count odd and even card at sx to the current (i) card
        for (int j = 0; j < i; j++)
            (_input_vett[j] % 2 == 0) ? even++ : odd++;
        // Check if left partition when pivot is i is removable
        if(even != odd)
            sx = false;

        // Reset counter for dx partition
        even = odd = 0;
        // Count odd and even card at dx to the current (i) card
        for (int j = i + 1; j < N; j++)
            (_input_vett[j] % 2 == 0) ? even++ : odd++;
        // Check if right partition when pivot is i is removable
        if(even != odd)
            dx = false;

        // Check if both partition are removable and push to answer's vector 
        if (dx && sx)
        {
            answer.push_back(_input_vett[i]);
        }
    }

    // Print answer
    cout << answer.size() << endl;
    for (int i = 0; i < answer.size() - 1; i++)
        cout << answer[i] << " ";
    cout << answer[answer.size() - 1] << endl;
}
