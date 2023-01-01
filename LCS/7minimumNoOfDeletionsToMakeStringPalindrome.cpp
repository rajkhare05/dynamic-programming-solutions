#include <bits/stdc++.h>
using namespace std;

int minimumNoOfDeletionsToMakeStringPalindrome(string s1, int n) {
	string s2 = s1;
	reverse(s2.begin(), s2.end());

	int m = n;

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

	return n - t[n][m];

}

int main() {

	int t;
	cin >> t;

	while (t--) {
		int n, m;
		cin >> n >> m;

		string s1, s2;
		cin >> s1 >> s2;

		int res = minimumNoOfDeletionsToMakeStringPalindrome(s1, n);

		cout << res << "\n";

	}
	
	return 0;
}
