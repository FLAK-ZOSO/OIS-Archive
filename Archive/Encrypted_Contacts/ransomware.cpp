/*
 * @Author: Enea Scaccabarozzi
 * @Date: 2022-03-13
 * @Problem: Encrypted Contacts
 * @Reference: https://training.olinfo.it/#/task/ois_ransomware/statement
 * @Big-O: O(N)
 */

#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

// constraints
const int MAXN = 100;

// input data
int N;
string contacts[MAXN];  // << Array with encrypted contacts
string codes[10];       // << Digit encoded


// Check if string start with a prefix that is equal to one of the encoded codes
int has_valid_start(string str)
{
    for(int i=0; i<10; i++)
    {
        if(str.substr(0, codes[i].length()) == codes[i]){
            return i;
        }
    }
    return -1;
}

int main() 
{
    //  uncomment the following lines if you want to read/write from files
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    // Get input
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> contacts[i];
    for (int i = 0; i < 10; i++)
        cin >> codes[i];

    string res;     // << result for each encrypted contact
    for (int i = 0; i < N; i++) {
        bool founded = false;   // A valid number has been founded
        for(int j=0; j<10; j++)     // Iterete trought codes to check every beginning prefix
        {
            if(founded) // Exit condition
                break;
            res = ""; 
            if(contacts[i].substr(0, codes[j].length()) == codes[j]) // check current prefix
            {
                string remaining = contacts[i].substr(codes[j].length()); // remaining encrypted contact
                res += to_string(j);
                bool possible = true; // With current prefix is still possible make a complete decrypted contact
                while(possible && remaining.length() > 0) // check if it is possible
                {
                    int digit = has_valid_start(remaining);
                    if(digit == -1)
                        possible = false;
                    else
                    {
                        res += to_string(digit);
                        remaining = remaining.substr(codes[digit].length() );
                    }
                }
                if(possible){
                    founded = true;
                }
            }
        }
        cout << res << endl;
    }
   
    return 0;
}
