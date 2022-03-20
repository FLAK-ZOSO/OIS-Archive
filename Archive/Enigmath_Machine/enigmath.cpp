/*
 * @Author: Enea Scaccabarozzi
 * @Date: 2022-03-13
 * @Problem: Enigmath Machine
 * @Reference: https://training.olinfo.it/#/task/ois_enigmath/statement
 * @Big-O: O(N)
 */

#include <iostream>
using namespace std;

// return the sum of all digits inside an n number given as paramether
int sum_digit(int n) {
    int sum = 0;

    do {
        sum += n % 10;
    } while (n /= 10);

    return sum;
}

// Crypt the input number with the given formula
int crypt(int n) {
    int res = n;
    while (n > 9) {
        int sum = sum_digit(n);
        res += sum;
        n = sum;
    }
    return res;
}

int main() {

    // read/write from files
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    // Input datas
    int min, max, start = 0;
    cin >> min;
    cin >> max;

    // 102 is hardcoded, and separated calculated, rapresenting the max distance between the number and is corrispondent crypted version in the first one billion N
    if (min >= 102) {
        start = min - 102;
    }

    // Save every solution (first = last decrypted N; second = number of occurrency of that number)
    pair<int, int> answer[1000000];

    // Iterate trought Ns
    for (int i = start; i <= max; i++) {
        int res = crypt(i);
        // check bounds
        if (res - min >= 0 && res - min <= 1000000) {
            // Update corresponding index
            answer[res - min].first = i;
            answer[res - min].second++;
        }
    }

    // Print results
    for (int i = 0; i <= max - min; i++) {
        if (answer[i].second == 1) {
            cout << answer[i].first << "\n";
        } else if (answer[i].second > 1) {
            cout << "AMBIGUOUS\n";
        } else {
            cout << "IMPOSSIBLE\n";
        }
    }
}