/*
 * @Author: Enea Scaccabarozzi
 * @Date: 2022-03-25
 * @Problem: Turni Di Guardia
 * @Reference: https://training.olinfo.it/#/task/turni/statement
 * @Big-O: O(N*logN)
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Cumstom struct to rapresent a shift
struct Shift
{
    int start;
    int end;
};

// Utils function to sort shifts
bool compare_shifts(const Shift &A, const Shift &B)
{
    if (A.end != B.end)
    {
        return A.end > B.end;
    }
    return A.start < B.start;
}

int main()
{
    // Read/write from files
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    // Number of day to be covered, Number of paperone's guards (Queue dimension)
    int K, N;

    // Get input
    cin >> K >> N;

    // Vector of shifts
    vector<Shift> shifts(N);

    // Get input
    for (int i = 0; i < N; i++)
        cin >> shifts[i].start >> shifts[i].end;

    // Sort ascending by start date (fallback to end date) shifts vector
    sort(shifts.begin(), shifts.end(), compare_shifts);

    // Count number of necessary guards
    int answer = 0;

    // Store day that is covered so far
    int current_end = -1;

    // Iterator for shift's vectors
    int itr = 0;

    // Check best shift at that moment until the days are fully covered
    while(current_end < K -1)
    {
        // Restart iteration from final shift
        itr = 0;

        // Get best shift from available ones
        while(shifts[itr].start > current_end + 1)
        {
            itr++;
        }

        // Update days covered
        current_end = shifts[itr].end;

        // Pay another guard
        answer++;
    }

    // Print answer
    cout << answer << endl;
}
