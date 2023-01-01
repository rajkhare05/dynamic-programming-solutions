#include <bits/stdc++.h>
using namespace std;

// MEMOIZATION: top down approach
int topDown(string s1, string s2, int n, int m, int t[][1001]) {
	if (n == 0 || m == 0) return 0;

	if (t[n][m] != -1) return t[n][m];

	if (s1[n - 1] == s2[m - 1])
		return t[n][m] = 1 + topDown(s1, s2, n - 1, m - 1, t);
	 
	return t[n][m] = max(topDown(s1, s2, n, m - 1, t), topDown(s1, s2, n - 1, m, t));
}

// TABULATION: bottom up approach
int bottomUp(string s1, string s2, int n, int m) {

	if (n == 0 || m == 0) return 0;

	int t[n + 1][m + 1];

	// init lookup table 't'
	for (int i = 0; i < n + 1; i++) t[i][0] = 0;
	for (int j = 0; j < m + 1; j++) t[0][j] = 0;

	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < m + 1; j++) {
			if (s1[i - 1] == s2[j - 1]) 
				t[i][j] = 1 + t[i - 1][j - 1];
			else 
				t[i][j] = max(t[i][j - 1], t[i - 1][j]);
		}
	}
	return t[n][m];
}

// Pure recursion approach 
int countLongestCommonSubsequence(string s1, string s2, int n, int m) {

	if (n == 0 || m == 0) return 0;

	int count = 0;

	if (s1[n - 1] == s2[m - 1]) {
		count = 1 + countLongestCommonSubsequence(s1, s2, n - 1, m - 1);
	
	} else {
		count = max(countLongestCommonSubsequence(s1, s2, n, m - 1), 
			countLongestCommonSubsequence(s1, s2, n - 1, m));
	}

	return count;
}

int main() {

	int t;
	cin >> t;

	while(t--) {
		string s1, s2;
		int n, m;
		cin >> n >> m;
		cin >> s1 >> s2;
		// int res = countLongestCommonSubsequence(s1, s2, n, m);

		// int t[1001][1001];
		// memset(t, -1, sizeof(t));
		// int res = topDown(s1, s2, n, m, t);
		
		int res = bottomUp(s1, s2, n, m);
		
		cout << res << "\n";
	}
	
	return 0;
}
