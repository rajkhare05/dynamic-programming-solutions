#include <bits/stdc++.h>
using namespace std;

// TABULATION: bottom up approach
string bottomUp(string s1, string s2, int n, int m) {

	if (n == 0 || m == 0) return "";

	string t[n + 1][m + 1];

	// init lookup table 't'
	for (int i = 0; i < n + 1; i++) t[i][0] = "";
	for (int j = 0; j < m + 1; j++) t[0][j] = "";

	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < m + 1; j++) {
			if (s1[i - 1] == s2[j - 1]) 
				t[i][j] = s1[i - 1] + t[i - 1][j - 1];
			else 
				t[i][j] = t[i][j - 1].size() > t[i - 1][j].size() 
						? t[i][j - 1] : t[i - 1][j];
		}
	}
	reverse(t[n][m].begin(), t[n][m].end());
	return t[n][m];
}

int main() {

	int t;
	cin >> t;

	while(t--) {
		string s1, s2;
		int n, m;
		cin >> n >> m;
		cin >> s1 >> s2;

		string res = bottomUp(s1, s2, n, m);
		
		cout << res << "\n";
	}
	
	return 0;
}
