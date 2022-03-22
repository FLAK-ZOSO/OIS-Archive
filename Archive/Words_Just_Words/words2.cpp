/*
 * @Author: Enea Scaccabarozzi
 * @Date: 2022-03-22
 * @Problem: Words, Just Words
 * @Reference: https://training.olinfo.it/#/task/ois_words2/statement
 * @Big-O: O(N)
 */

#include <iostream>

using namespace std;

// Define base of that alphabet (English one)
#define BASE 26

// Define result module
#define BOUND 1000000007

// Input string
string W;

// Get integer value of a char, starting from 'a'
int get_integer(char A)
{
    return (int)A - 96;
}

// Execute pow inside a specific module (Stackoverflow)
long long int pow_modular(long long int a, long long int b, long long int n)
{
    long long x = 1, y = a;
    while (b > 0)
    {
        if (b % 2 == 1)
        {
            x = (x * y) % n; // multiplying with base
        }
        y = (y * y) % n; // squaring the base
        b /= 2;
    }
    return x % n;
}

int main()
{
    // Uncomment the following lines if you want to read/write from files
    //ifstream cin("input2.txt");
    //ofstream cout("output.txt");

    // Get input string
    cin >> W;

    // Init base 10 value
    unsigned long long res = -1;

    // Convert from base 26 to base 10
    for (int i = 0; i < W.length(); i++)
    {
        res += get_integer(W[W.length() - 1 - i]) * (pow_modular(BASE, i, BOUND));
        res = res % BOUND;
    }

    // Print answer
    cout << res << endl;
    return 0;
}
