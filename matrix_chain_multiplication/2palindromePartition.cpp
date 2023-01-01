#include <bits/stdc++.h>
using namespace std;
class Solution {
public:

	bool isPalindrome(string s) {
		int i = 0;
		int j = s.size() - 1;

		while (i < j) {
			if (s[i] != s[j]) return false;
			i++;
			j--;
		}
		return true;
	}

	// Bottom up (R + memoization)
	int solve(string s, int i, int j, int t[101][101]) {
		
		// Base condition (can vary)
		if (i >= j) return 0;
		if (isPalindrome(s)) return 0;

		if (t[i][j] != -1) return t[i][j];

		int minCost = INT_MAX;

		for (int k = i; k <= j - 1; k++) {
			int left = (t[i][k] != -1) ? t[i][k] : solve(s, i, k, t);
			int right = (t[k + 1][j] != -1) ? t[k + 1][j] : solve(s, k + 1, j, t);
			int temp =  left + right + 1;
			minCost = min(minCost, temp);
		}

		return t[i][j] = minCost;
	}
};

int main() {
	int t, N;
	cin >> t;

	while (t--) {
		string s;
		cin >> s;
		int N = s.size();
		int t[101][101];
		memset(t, -1, sizeof(t));
		Solution S;
		cout << S.solve(s, 0, N - 1, t) << "\n";
	}
	return 0;
}
/*
ababbbabbababa
abba
nitik
nitin
aabb
aaabba
*/
/*
13 -> Wrong
0
4
0
3 -> Wrong
5 -> Wrong
*/
