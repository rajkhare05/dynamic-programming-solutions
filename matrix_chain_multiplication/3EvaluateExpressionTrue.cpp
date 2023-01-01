#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> m;

class Solution {
public:

	void print_map(unordered_map<string, int> &m) {
		for (auto it = m.begin(); it != m.end(); it++) {
			cout << it->first << "->" << it->second << "\n";
		}
	}

	string createKey(int i, int j, bool isTrue) {
		string key = to_string(i);
		key.push_back(' ');
		key += to_string(j);
		key.push_back(' ');
		key += to_string(isTrue);
		return key;
	}

	int eval_exp(char &optr, int &lt, int &lf, int &rt, int &rf, bool &isTrue) {
		int ans = 0;
		if (optr == '&') {
			if (isTrue) ans += (lt * rt);
			else ans += (lt * rf) + (lf * rt) + (lf * rf);

		} else if (optr == '|') {
			if (isTrue) ans += (lt * rt) + (lt * rf) + (lf * rt);
			else ans += (lf * rf);

		} else if (optr == '^') {
			if (isTrue) ans += (lt * rf) + (lf * rt);
			else ans += (lt * rt) + (lf * rf);
		}

		return ans;
	}

	int solve(string s, int i, int j, bool isTrue) {
		if (i > j) return 0;
		if (i == j) {
			if (isTrue) return s[i] == 'T' ? 1 : 0;
			else return s[i] == 'F' ? 1 : 0;
		}

		string key = createKey(i, j, isTrue);

		if (m.find(key) != m.end()) return m[key];

		int ans = 0;

		for (int k = i + 1; k <= j - 1; k = k + 2) {
			int lt = solve(s, i, k - 1, true);
			int lf = solve(s, i, k - 1, false);
			int rt = solve(s, k + 1, j, true);
			int rf = solve(s, k + 1, j, false);
			ans += eval_exp(s[k], lt, lf, rt, rf, isTrue);
		}

		return m[key] = ans % 1003;
	}
};

int main() {
	int t;
	cin >> t;
	while (t--) {
		string str;
		cin >> str;
		Solution S;
		int N = str.size();
		m.clear();
		cout << S.solve(str, 0, N - 1, true) << "\n";
		// print_map(m);
	}	
	return 0;
}
/*
4
T|F^F&T|F^F^F^T|T&T^T|F^T^F&F^T|T^F
T|T&F^T
T^F|F
T|F&T^F
*/
/*
638
4
2
5
*/
