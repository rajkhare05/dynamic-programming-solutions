#include <bits/stdc++.h>
using namespace std;

// TABULATION: bottom up approach
int bottomUp(string s1, string s2, int n, int m) {

	if (n == 0 || m == 0) return 0;

	int t[n + 1][m + 1];

	// init lookup table 't'
	for (int i = 0; i < n + 1; i++) t[i][0] = 0;
	for (int j = 0; j < m + 1; j++) t[0][j] = 0;

	int count = 0;

	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < m + 1; j++) {
			
			if (s1[i - 1] == s2[j - 1])
				t[i][j] = 1 + t[i - 1][j - 1];
			
			else 
				t[i][j] = 0;

			count = max(count, t[i][j]);
		}
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
		int res = bottomUp(s1, s2, n, m);
		
		cout << res << "\n";
	}
	
	return 0;
}
