#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

	int solve(int arr[], int i, int j) {

		// Base condition (can vary)
		if (i >= j) return 0;

		int minCost = INT_MAX;

		for (int k = i; k <= j - 1; k++) {
			int temp =   solve(arr, i, k) 
					   + solve(arr, k + 1, j)
					   + (arr[i - 1] * arr[k] * arr[j]);

			minCost = min(minCost, temp);
		}

		return minCost;
	}

	// Bottom up (R + memoization)
	int solve(int arr[], int i, int j, int t[101][101]) {
		
		// Base condition (can vary)
		if (i >= j) return 0;

		if (t[i][j] != -1) return t[i][j];

		int minCost = INT_MAX;

		for (int k = i; k <= j - 1; k++) {
			int temp =   solve(arr, i, k, t) 
					   + solve(arr, k + 1, j, t)
					   + (arr[i - 1] * arr[k] * arr[j]);

			minCost = min(minCost, temp);
		}

		return t[i][j] = minCost;
	}

};

int main() {
	int t, N;
	cin >> t;

	while (t--) {
		cin >> N;
		int arr[N];

		for (int i = 0; i < N; i++) {
			cin >> arr[i];
		}

		int t[101][101];
		memset(t, -1, sizeof(t));
		Solution S;
		cout << S.solve(arr, 1, N - 1, t) << "\n";
	}

	return 0;
}
/*
4
10 30 5 60
5
40 20 30 10 30
*/
// 4500
// 26000
