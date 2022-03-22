/*
 * @Author: Enea Scaccabarozzi
 * @Date: 2022-03-22
 * @Problem: Do Not Gather!
 * @Reference: https://training.olinfo.it/#/task/ois_gatherings/statement
 * @Big-O: O(N)
 */

#include <iostream>
using namespace std;

// Constraints
#define MAXN 100000

// Number of person (array dimension), Min distance required
int N, D;

// Array of persons (Strictly sorted)
int P[MAXN];

int main()
{
    //  uncomment the following lines if you want to read/write from files
    //freopen("input1.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    // Get input
    cin >> N >> D;
    for (int i = 0; i < N; i++)
        cin >> P[i];

    // Counter of person tht doesn't respect social distance
    long long answer = 0;

    // Iterators
    int i = 0;
    int j = 1;
    while (i < N - 1)
    {
        if (P[j] - P[i] >= D || j >= N)
        {
            answer += j - i - 1;
            i++;
        }
        else
            j++;
    }

    // Print answer
    cout << answer << endl; 
    return 0;
    
}
