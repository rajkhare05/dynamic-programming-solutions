#include <bits/stdc++.h>
using namespace std;

// minimum no. of insertions and deletions
// to convert string a to b

// TABULATION: bottom up approach
int minimumNoOfInsertionAndDeletion(string s1, string s2, int n, int m) {

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

	int minDeletions = n - t[n][m];

	int minInsertions = m - t[n][m];

	int minimumOps = minDeletions + minInsertions;
	
	return minimumOps;
}

int main() {

	int t;
	cin >> t;

	while(t--) {
		string s1, s2;
		int n, m;
		cin >> n >> m;
		cin >> s1 >> s2;
		
		int res = minimumNoOfInsertionAndDeletion(s1, s2, n, m);
		
		cout << res << "\n";
	}
	
	return 0;
}
