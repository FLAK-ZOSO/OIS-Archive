/*
 * @Author: Enea Scaccabarozzi
 * @Date: 2022-03-27
 * @Problem: Viaggio In Taxi
 * @Reference: https://training.olinfo.it/#/task/taxi/statement
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

    // Number of city from Brescia to Pinerolo
    int N;

    // Get input
    cin >> N;

    // Vector of city between starting point and destination
    vector<int> city(N);

    // Get input
    for (int i = 0; i < N; i++)
        cin >> city[i];

    // Store minimun price to reach destination
    long long answer = city[0];

    // Store current price to go at next city
    int current_price = city[0];

    // Iterate trought city
    for (int i = 1; i < N; i++)
    {
        current_price++;
        current_price = min(current_price, city[i]);
        answer += current_price;
    }

    // Print answer
    cout << answer << endl;
}