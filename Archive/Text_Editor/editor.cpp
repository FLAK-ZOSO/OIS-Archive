/*
 * @Author: Enea Scaccabarozzi
 * @Date: 2022-03-22
 * @Problem: Text Editor
 * @Reference: https://training.olinfo.it/#/task/ois_editor/statement
 * @Big-O: O(N)
 */

#include <iostream>
#include <cstring>
using namespace std;

// Constraints
#define MAXN 1000000

// String dimension
int N;

// Input string
char V[MAXN];

// Utilis to check if a char correspond to bold
bool is_bold(char c)
{
	return isupper(c);
}

// Utilis to check if a char correspond to italic
bool is_italic(char c)
{
	return (c == 'i' || c == 'I');
}

int main()
{
	//  Uncomment the following lines if you want to read/write from files
	//  freopen("input1.txt", "r", stdin);
	//  freopen("output.txt", "w", stdout);

	// Number of strokes required (Answer)
  	int strokes = 0;

	// Get input
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> V[i];

	// Iterate trought string and count how many bold segment there are
	for (int i = 0; i < N; i++)
	{
		if (is_bold(V[i]))
		{
			strokes++;
			i++;
			while (is_bold(V[i]) && i < N)
				i++;
		}
	}

	// Iterate trought string and count how many italic segment there are
	for (int i = 0; i < N; i++)
	{
		if (is_italic(V[i]))
		{
			strokes++;
			i++;
			while (is_italic(V[i]) && i < N)
				i++;
		}
	}

	// Print answer
	cout << strokes << endl; 
	return 0;
}