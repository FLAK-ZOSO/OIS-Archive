/*
 * @Author: Enea Scaccabarozzi
 * @Date: 2022-03-28
 * @Problem: Convegno Aziendale
 * @Reference: https://training.olinfo.it/#/task/mat_convegno/statement
 * @Big-O: O(N)
 */

#include <iostream>
#include <vector>
using namespace std;

// Vector of solutions (Store number of cuples creable from that employee)
vector<int> answer;

// Recursive function to sove employee with index i
int solve(int i, int *_input, int N)
{
	// Base case (Employee is director)
	if (_input[i] == -1)
	{
		// Director has got zero cuples creable
		answer[i] = 0;
	}
	// Otherwise check if current employee is already computed
	else if (answer[i] == -1)
	{
		// If not add 1 to solution of parent employee
		answer[i] = solve(_input[i], _input, N) + 1;
	}

	// Return computed answer
	return answer[i];
}

// Driver code (Main inside grader)
int coppie(int N, int *C)
{
	// Resize answer vector && fill with uncomputed values
	answer.resize(N);
	fill(answer.begin(), answer.end(), -1);

	// Store how many cuples are creable
	int total = 0;

	// Compute solution for each employee and sum them
	for (int i = 0; i < N; i++)
		total += solve(i, C, N);

	// Print answer
	return total;
}
