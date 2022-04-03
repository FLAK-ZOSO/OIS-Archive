/*
 * @Author: Enea Scaccabarozzi
 * @Date: 2022-04-03
 * @Problem: Domino Massimale
 * @Reference: https://training.olinfo.it/#/task/domino/statement
 * @Big-O O(??) (I am unable to calucalte it, but is pretty high)
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Util struct to rapresent each card
struct Card
{
    int top;
    int bottom;
};

// Number of cards (Vector dimension)
int N;

// Vecotr of cards
vector <Card> _input;

// Store if the card i is already taken or not
vector <bool> taken;

// Return max chain size from a starting chain
int solve(int sx, int dx, int chain)
{
    // Store answer
    int best_sub_chain = chain;

    // Iterate trought cards
    for(int i=0; i<N; i++)
    {
        // If current card is already taken skip it 
        if(taken[i])
            continue;

        /* 
         * Check if current card is linkable to the chain
         * If so set it to taken for current subchain and compute best sub chain size
         * Compare it with the better one found so far, if better sobstitute it
         */

        // Match sx of chain with top of current card
        if(_input[i].top == sx)
        {
            taken[i] = true;
            best_sub_chain = max(best_sub_chain, solve(_input[i].bottom, dx, chain + 1));
            taken[i] = false;
        }

        // Match dx of chain with top of current card
        if(_input[i].top == dx)
        {
            taken[i] = true;
            best_sub_chain = max(best_sub_chain, solve(sx, _input[i].bottom, chain + 1));
            taken[i] = false;
        }

        // Match sx of chain with bottom of current card
        if(_input[i].bottom == sx)
        {
            taken[i] = true;
            best_sub_chain = max(best_sub_chain, solve(_input[i].top, dx, chain + 1));
            taken[i] = false;
        }

        // Match dx of chain with bottom of current card
        if(_input[i].bottom == dx)
        {
            taken[i] = true;
            best_sub_chain = max(best_sub_chain, solve(sx, _input[i].top, chain + 1));
            taken[i] = false;
        }
    }

    // Return better sub chain size founded
    return best_sub_chain;
}

int main()
{
    // Read/write from files
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    // Get input
    cin >> N;

    // Set actual vectors dimension
    _input.resize(N);
    taken.resize(N);

    // Init taken vector to untaken
    fill(taken.begin(), taken.end(), false);

    // Get input 
    for(int i=0; i<N; i++)
        cin >> _input[i].top >> _input[i].bottom;

    // Store maximum chain of cards
    int answer = 0;

    // Iterate trought vector and check each starting card
    for(int i=0; i<N; i++)
    {
        // Take i card
        taken[i] = true;

        // Compute best chain so far
        answer = max(answer, solve(_input[i].top, _input[i].bottom, 1));

        // Untake i card for next chains
        taken[i] = false;
    }

    // Print answer
    cout << answer << endl;
}
