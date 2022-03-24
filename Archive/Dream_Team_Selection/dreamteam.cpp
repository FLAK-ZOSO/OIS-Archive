/*
 * @Author: Enea Scaccabarozzi
 * @Date: 2022-03-24
 * @Problem: Drea Team Selection
 * @Reference: https://training.olinfo.it/#/task/ioit_dreamteam/statement
 * @Big-O: O(N)
 */

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Coder
{
    // Score by himself
    int main_score;

    // Score with friend
    int sub_score;

    // Best firend index
    int best_friend;

    // Real score (with a friend in team)
    int real_score;
};

bool sort_by_real_score(Coder A, Coder B) { return A.real_score > B.real_score; }

int main()
{
    // Read/Write from input
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    // Number of coders (Vector dimesion), Players in final team
    int N, K;
    cin >> N >> K;

    // Coders vector
    vector<Coder> coders(N);

    // Dummy var for input
    Coder dummy;

    // Get input && calculate real scores
    for (int i = 0; i < N; i++)
    {
        cin >> dummy.best_friend >> dummy.main_score >> dummy.sub_score;
        dummy.real_score = dummy.main_score;
        coders[i] = dummy;

        // Check if best friend is already present
        if (coders[i].best_friend < i)
        {
            // Temp Var to improve readbility
            int best_friend = coders[i].best_friend;

            // Check which friend is better
            if (coders[i].main_score > coders[best_friend].main_score)
            {
                // Update worst friend real score in order to comprend his sub score minus the malus that inflict to the better friend
                coders[best_friend].real_score = coders[best_friend].sub_score - (coders[i].main_score - coders[i].sub_score);
            }
            else
            {
                // Update worst friend real score in order to comprend his sub score minus the malus that inflict to the better friend
                coders[i].real_score = coders[i].sub_score - (coders[best_friend].main_score - coders[best_friend].sub_score);
            }
        }
    }

    // Sort by real score
    sort(coders.begin(), coders.end(), sort_by_real_score);

    // Store best combination of scores
    int answer = 0;

    for(int i=0; i<K; i++)
    {
        answer += coders[i].real_score;
    }

    // Print answer
    cout << answer << endl;
}
