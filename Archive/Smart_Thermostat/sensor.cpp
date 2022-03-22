/*
 * @Author: Enea Scaccabarozzi
 * @Date: 2022-03-22
 * @Problem: Smart Thermostat
 * @Reference: https://training.olinfo.it/#/task/ois_sensor/statement
 * @Big-O: O(N)
 */

#include <stdio.h>
#include <assert.h>

// Constraints
#define MAXN 100000

// Number of registrations (Array dimension)
int N;

// Array of registrations
int V[MAXN];

int main()
{
    //  uncomment the following lines if you want to read/write from files
    //  freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);

    // Get input
    assert(1 == scanf("%d", &N));
    assert(1 == scanf("%d", &V[0]));

    // Init zero position
    if (V[0] == -1)
    {
        V[0] = 0;
    }

    // Init sum (Answer)
    int sum = V[0];

    // Iterate trought registrations array
    for (int i = 1; i < N; i++)
    {
        // Get remaining registrations from input
        assert(1 == scanf("%d", &V[i]));

        // Check if cuttent is negative
        if (V[i] == -1)
        {
            V[i] = V[i - 1];
        }

        // Update answer
        sum += V[i];
    }

    // Print Answer
    printf("%d\n", sum);
    return 0;
}
