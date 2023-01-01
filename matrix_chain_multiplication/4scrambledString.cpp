#include <bits/stdc++.h>
using namespace std;

unordered_map<string, bool> m;

class Solution {
public:

	string createKey(string a, string b) {
		string key = a;
		key.push_back(' ');
		key.append(b);
		return key;
	}

	bool solve(string a, string b) {
		if (a.compare(b) == 0) return true;
		if (a.size() <= 1) return false;

		string key = createKey(a, b);

		if (m.find(key) != m.end()) return m[key];

		int N = a.size();
		bool flag = false;

		for (int i = 1; i <= N - 1; i++) {
			if ((solve(a.substr(0, i), b.substr(N - i, i)) &&
				 solve(a.substr(i, N - i), b.substr(0, N - i)))
					||
				(solve(a.substr(0, i), b.substr(0, i)) &&
				 solve(a.substr(i, N - i), b.substr(i, N - i)))
			   )
			{
				flag = true;
				break;
			}
		}
		return m[key] = flag;
	}
};

int main() {
	int t;
	cin >> t;
	while (t--) {
		string a, b;
		cin >> a >> b;
		Solution S;
		m.clear();
		bool ans;
		if (a.size() != b.size()) ans = false;
		else if (a.size() == 0 && b.size() == 0) ans = true;
		else ans = S.solve(a, b);
		if (ans) cout << "Yes";
		else cout << "No";
		cout << "\n";
	}
	return 0;
}
