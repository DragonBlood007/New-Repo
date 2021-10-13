/* C++ program to count number of sub-arrays in which
number of occurrence of x is equal to that of y
	using brute force */
#include <bits/stdc++.h>
using namespace std;

int sameOccurrence(int arr[], int n, int x, int y)
{
	int result = 0;

	// Check for each subarray for the required condition
	for (int i = 0; i <= n - 1; i++) {
		int ctX = 0, ctY = 0;
		for (int j = i; j <= n - 1; j++) {
			if (arr[j] == x)
				ctX += 1;
			else if (arr[j] == y)
				ctY += 1;
			if (ctX == ctY)
				result += 2;		
		}
	}

	return (result);
}

// Driver code
int main()
{
	int arr[] = { 1, 2, 2, 3, 4, 1 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int x = 2, y = 3;
	cout << sameOccurrence(arr, n, x, y);
	return (0);
}
