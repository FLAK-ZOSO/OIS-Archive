/*
 * @Author: Enea Scaccabarozzi
 * @Date: 2022-04-04
 * @Problem: Mappa Antica
 * @Reference: https://training.olinfo.it/#/task/mappa/statement
 * @Big-O O(??) (I am unable to calucalte it, but is pretty high)
 */

#include <iostream>
using namespace std;

// Costrains
#define MAXLEN 102

// Matrix that rapresent already steps spots (Infinite recursion)
// Has a border of invalicable
int steps[MAXLEN][MAXLEN];

// Actual maze side
int N;

// Recursive function to fill the maze with minimum steps required to reach every spot
void solve(int x, int y)
{
    // Check adiacent spots
    for(int i= - 1; i < 2; i++)
    {
        for(int j= - 1; j < 2; j++)
        {
            // Check if current spot is outside borders
            if(x + i >= 0 && y + j >= 0 && x + i < N && y + j < N)
            {
                // Check if itsn't an obstacle
                if(steps[x + i][y + j] != -1)
                {
                    // Check if current stpo it has a worst scrore than the one of the standing one plus one
                    // or if it is still unstepped
                    if(steps[x + i][y + j] > steps[x][y] + 1 || steps[x + i][y + j] == 0)
                    {
                        // Update score
                        steps[x + i][y + j] = steps[x][y] + 1;
                        
                        // Solve maze from that spot
                        solve(x + i, y + j);
                    }
                }
            }
        }
    }
}

int main()
{
    // Read/write from files
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    // Get input
    cin >> N;

    // Dummy var for input managment
    char dummy;

    // Init steps
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            cin >> dummy;
            steps[i][j] = (dummy == '+') ? -1 : 0; 
        }
    }

    // Starting spot must be counted
    steps[0][0] = 1;

    // Aptempt to solve the maze 
    solve(0, 0);

    // Print answer
    cout << steps[N-1][N-1]<< endl;
}
