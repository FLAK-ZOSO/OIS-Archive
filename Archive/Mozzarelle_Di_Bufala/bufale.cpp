/*
 * @Author: Enea Scaccabarozzi
 * @Date: 2022-03-25
 * @Problem: Mozzarelle di Bufala
 * @Reference: https://training.olinfo.it/#/task/bufale/statement
 * @Big-O: O(N*logN)
 */

#include <iostream>
#include <algorithm>
using namespace std;

// Custom struct to define the real rating of a mozzarella
struct Rating
{
    int REAL_score;
    int index;
};

// Utility function to partition array of Ratings
bool compare_rating(Rating &A, Rating &B){ return A.REAL_score > B.REAL_score; }

// Main is definied by the grader
long long solve(int N, int* M, int* P)
{
    // Vector of mozzarella's real scores
    Rating real_scores[N];

    // Get input
    for(int i=0; i<N; i++)
    {
        // Calculate real score as difference between Paolo and Maria scores
        real_scores[i].REAL_score = M[i] - P[i];
        
        // Keep trace of indexes even after partitioning
        real_scores[i].index = i;
    }

    // Store sum of max Paolo and Maria sums of ratings
    long long answer = 0;

    // Partition array at mid element
    nth_element(real_scores, real_scores + N / 2, real_scores + N, compare_rating);

    // Select best scores
    for(int i=0; i<N/2; i++)
    {
        answer += M[real_scores[i].index] + P[real_scores[N - 1 - i].index];
    }

    // Return answer
    return answer;
}