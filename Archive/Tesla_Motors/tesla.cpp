/*
 * @Author: Enea Scaccabarozzi
 * @Date: 2022-03-22
 * @Problem: Tesla Motors
 * @Reference: https://training.olinfo.it/#/task/gator_tesla/statement
 * @Big-O: O(N)
 */

#include <iostream>
using namespace std;

// Constrains
#define MAXN 100000

// Input nodes
size_t circular_vector[MAXN];


int main()
{
    // Read/write from files
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    // Array size (Number of nodes)
    size_t N;

    // Get input values
    cin >> N;
    for(size_t i=0; i<N; i++)
        cin >> circular_vector[i];

    // Current checked starting node
    size_t start; 

    // Array iterator
    size_t iterator = 0;

    // Current value of remaining charge (Init value usless)
    int sum = -1;

    // Iterate trought vector
    do
    {
        // Restart control from new starting node
        if(sum < 0)
        {
            start = iterator;
            sum = circular_vector[iterator] - 10;
        } 
        // Move to next node
        else 
        {
            sum += circular_vector[iterator] -10;
        }

        // Increment iterator (Circular array)
        (iterator == N-1) ? iterator = 0 : iterator++;
    } while (iterator != start); // When current position equal start, start is a valid solution

    // Indexed from 1
    cout << start + 1<< endl;
}
