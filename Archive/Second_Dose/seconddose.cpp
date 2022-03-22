/*
 * @Author: Enea Scaccabarozzi
 * @Date: 2022-03-22
 * @Problem: Second Dose
 * @Reference: https://training.olinfo.it/#/task/ois_seconddose/statement
 * @Big-O: O(N^2)
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Constraints
#define MAXN 100000

// First dose dimension, Second Dose dimension
int N1, N2;

// First dose vector, Second dose array
vector<int> ID1, ID2;

int main()
{
    // Get input
    cin >> N1 >> N2;
    ID1.resize(N1);
    ID2.resize(N2);
    for (int i = 0; i < N1; i++)
        cin >> ID1[i];
    for (int i = 0; i < N2; i++)
        cin >> ID2[i];

    // Sort vectors
    sort(ID1.begin(), ID1.end());
    sort(ID2.begin(), ID2.end());

    // Second dose counter (Answer)
    long long int ans = 0;

    // Iterator
    int j = 0;

    // Iterate tought second vector
    for (int i = 0; i < N2; i++)
    {
        while (ID1[j] < ID2[i] && j < N1)
        {
            j++;
        }
        if (ID2[i] == ID1[j])
        {
            //cerr << "[FOUNDED]"<< endl;
            ans++;
            j++;
        }
    }

    // Print results
    cout << ans << endl;
    return 0;
}
