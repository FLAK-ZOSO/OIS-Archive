/*
 * @Author: Enea Scaccabarozzi
 * @Date: 2022-03-22
 * @Problem: Solving Wordle
 * @Reference: https://training.olinfo.it/#/task/ois_wordle/statement
 * @Big-O: O(N)
 */

#include <iostream>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    // String lenght
    int length;
    cin >> length;
    
    // Known letters
    int letters = 0;
    
    // Get string from input
    for (int i = 0; i < length; i++) {
        string letter;
        cin >> letter;
        if (letter != "_") {
            letters++;
        }
    }

    // Init missing letters
    int numOfLettersAvailable = 26 - letters;
    
    // Init answer
    int counter = 1;
    
    // Calculate factorial of missing letters
    for (int i = letters; i < length; i++) {
        counter = counter * numOfLettersAvailable;
        numOfLettersAvailable--;
    }

    // Print answer
    cout << counter;
}