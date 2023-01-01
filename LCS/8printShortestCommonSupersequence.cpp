#include <bits/stdc++.h>
using namespace std;
// print shortest common super sequence 
// TABULATION: bottom up approach
string SCSuperSeq(string s1, string s2, int n, int m) {

	if (n == 0 || m == 0) return "";

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

	int i = n, j = m;
	string res = "";

	while (i > 0 && j > 0) {
		if (s1[i - 1] == s2[j - 1]) {
			res.push_back(s1[i - 1]);
			i--;
			j--;

		} else {
			if (t[i][j - 1] > t[i - 1][j]) {
				res.push_back(s2[j - 1]);
				j--;

			} else {
				res.push_back(s1[i - 1]);
				i--;
			}
		}
	}

	while (i > 0) {
		res.push_back(s1[i - 1]);
		i--;
	}

	while (j > 0) {
		res.push_back(s2[j - 1]);
		j--;
	}

	reverse(res.begin(), res.end());
	return res;
}

int main() {

	int t;
	cin >> t;

	while(t--) {
		string s1, s2;
		int n, m;
		cin >> n >> m;
		cin >> s1 >> s2;

		string res = SCSuperSeq(s1, s2, n, m);
		
		cout << res << "\n";
	}
	
	return 0;
}
