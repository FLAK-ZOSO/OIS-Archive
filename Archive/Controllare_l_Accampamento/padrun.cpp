/*
 * @Author: Enea Scaccabarozzi
 * @Date: 2022-03-28
 * @Problem: Controllare L'Accampamento
 * @Reference: https://training.olinfo.it/#/task/padrun/statement
 * @Big-O: O(N)
 */

#include <iostream>
#include <vector>
using namespace std;

// Custom data type to rapresent a shift
struct Shift
{
	int start;
	int end;
};

// Number of shifts (Vector dimension)
int N;

// Vector of shifts recived from input
vector<Shift> _input;

/*
 * @decriptor: Utility function to find the better shift (that cover an 
 * uncovered shift with the maximum end possible) given a starting shift
 * (that is certantly already covered by another shift)
 * 
 * @return: Index of better shift founded
 * 
 * @param: unc -> Integer that rapresent the index of the shift to be covered
 * @param: starting_point -> Integer hat rapresent the index of the most advanced shift 
 * that is shurely covered
 */
int find_better(int unc, int starting_point)
{
	// Store the current better shift
	int better = unc;

	// Iterate trought vector from starting point (or 0 if unset)
	for (int i = max(0, starting_point); i < N; i++)
	{
		// Check if current shift doesn't cover the uncovered shift
		if (_input[i].start > _input[unc].end)
		{
			// If so stop cycle
			break;
		}
		// Check if current shift is the best one so far
		if (_input[better].end < _input[i].end)
		{
			// If so update better variable
			better = i;
		}
	}

	// Return better shift
	return better;
}

/*
 * @decriptor: Utility function to find the next uncovered shift after a given 
 * shift (already covered)
 * 
 * @return: Index of uncovered shift founded, or -1 if all shifts are covered
 * 
 * @param: cov -> Integer that rapresent the index of the shift already 
 * covered (starting point for the research)
 */
int find_next_uncovered(int cov)
{
	// Iterate trought vector from starting point
	for (int i = cov + 1; i < N; i++)
	{
		// Check if current shift is uncovered
		if (_input[i].start > _input[cov].end)
		{
			// If so return current index
			return i;
		}
	}

	// If no uncovered shift has been fuond return -1
	return -1;
}

/*
 * @decriptor: Utility function to find the shift that has minimum end and
 * is included in a given shift (uncovered)
 * 
 * @return: Index of included shift founded
 * 
 * @param: unc -> Integer that rapresent the index of the uncovered shift 
 * in wich search for included shifts
 */
int find_included(int unc)
{
	// Store index of included shift with minimum end
	int first = unc;

	// Iterate trought vector to search included shifts
	for (int i = unc + 1; i < N; i++)
	{
		// Check if current shift start after unc
		if (_input[i].start > _input[unc].end)
		{
			// If so stop loop
			break;
		}

		// Check if current shift has the lowest end
		if (_input[i].end < _input[first].end)
		{
			// If so update first
			first = i;
		}
	}

	// Return founded shift 
	return first;
}

// Driver code
int main()
{
	// Read/write from files
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	// Get input
	cin >> N;

	// Set vector dimension
	_input.resize(N);

	// Get input
	for (int i = 0; i < N; i++)
		cin >> _input[i].start >> _input[i].end;

	// Store current first uncovered shift
	int uncovered = 0;

	// Store shift taken at each iteration
	int covered;

	// Store previous taken shift (To define starting point for find_better)
	int previous_covered = -1;

	// Store minimum number of shifts that solve task
	int answer = 0;

	// Cycle until all shifts are covered
	while (uncovered != -1)
	{
		// Add new shift to answer
		answer++;

		// Check for included shifts
		uncovered = find_included(uncovered);

		// Find better shift that covere actual uncovered shift
		covered = find_better(uncovered, previous_covered);

		// Update previous covered shift
		previous_covered = covered;

		// Check for next uncovered shifts
		uncovered = find_next_uncovered(covered);
	}

	// Print answer
	cout << answer << endl;
}
