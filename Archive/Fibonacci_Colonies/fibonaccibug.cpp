/*
 * Author: Enea Scaccabarozzi
 * Date: 2022-03-12
 * Problem: Fibonacci Colonies
 * Reference: https://training.olinfo.it/#/task/ois_fibonaccibug/statement
 */

#include <iostream>
#include <cmath>
using namespace std;

// constraints
#define MAXN 100000
#define MAX_GRADE 25

long long int T;                          // << Days number
long long int N;                          // << Offers for day
long long int K;                          // << Max ants sellable
long long int Ants_global[MAX_GRADE];     // << Ants per degree [FIBONACCI]

// Offer arrays
long long int A[MAXN];            // << Degree array
long long int B[MAXN];            // << Prices array

bool check1(long long int d) {
    if (d >= 1 && d <= 100000)
        return true;
    return false;
}

bool check2(long long int e) {
    if (e >= 1 && e <= pow(10, 9)) {
        return true;
    }
    return false;
}


// Dynamic fibonacci, nothing special
long long int Fibonacci(long long int n) {
    Ants_global[0] = 1;
    Ants_global[1] = 1;
    for (long long int i=2; i < n; i++)
        Ants_global[i] = Ants_global[i - 1] + Ants_global[i - 2];

    return Ants_global[n - 1];
}

// Max utils
long long int max(long long int a, long long int b) {
    return (a > b) ? a : b;
}

long long int solve(long long int offers, long long int required[],long long int price[],long long int MAX_sellable)
{
    // Store sub solutions
    long long int dp[MAX_sellable+1];

    // Init sub solutions
    for(long long int i=0;i<MAX_sellable+1;i++)
        dp[i]=0;
    
    
    // Load sub solutions
    for(long long int i=0;i<offers;i++)
    {
        // Get number of ants required
        long long int actual_request = Ants_global[required[i]];
        
        if (required[i] < MAX_GRADE && check1(offers) && check1(MAX_sellable) && check2(Ants_global[required[i]])) 
        {
            for(long long int j=actual_request;j<MAX_sellable+1;j++)
                dp[j]=max(dp[j],price[i]+dp[j-actual_request]);
        }
    }
        

    // return solution for MAX SELLABLE ANTS
    return dp[MAX_sellable];
}

// Knapsac problem (Senza limiti)
int main() 
{
    //freopen("input0.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    // Init days number
    cin >> T; 
    
    // Init ants per grade
    Fibonacci(MAX_GRADE);

    // Compute for each day
    for(long long int i=0; i<T; i++)
    {
        // Init offers number [N] and max sellable ants [K]
        cin >> N >> K;

        // Init offers 
        for(long long int j=0; j<N; j++)
            cin >> A[j] >> B[j];
        
        // Solve day i
        cout << solve(N, A, B, K) << endl;
    }
    return 0;
}