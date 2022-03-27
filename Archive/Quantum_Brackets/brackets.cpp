/*
 * @Author: Enea Scaccabarozzi
 * @Date: 2022-03-27
 * @Problem: Quantum Brackets
 * @Reference: https://training.olinfo.it/#/task/ois_brackets/statement
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

    // Number of espression that has to be checked
    size_t T;

    // Get input
    cin >> T;

    // Number of parenthesis (Vector dimension), Number of types of parenthesis 
    size_t N, K;

    // Vector that store the espression to be checked (Used as a stack, with better memeory efficensy)
    vector <size_t> espression;

    // Solve tests
    for(size_t i=0; i<T; i++)
    {
        // Clear vector
        espression.clear();

        // Get input
        cin >> N >> K;

        // Temp var for input managment
        size_t dummy;

        // Init vector with first element
        cin >> dummy;
        espression.push_back(dummy);

        // Get input && start validating
        for(size_t i=1; i<N; i++)
        {
            // Insert current parenthesis
            cin >> dummy;

            // If it is matchable with last insterted element
            if(dummy == espression[espression.size()-1])
                // If so remove both of them (In fact remove only the one already inserted)
                espression.pop_back();
            else
                // If not push to vector the new parenthesis
                espression.push_back(dummy);
        }
        
        // If vector is empty all brackets are matched
        if(espression.empty())
            cout << 1 << endl;
        else 
            cout << 0 << endl;
    }
}
