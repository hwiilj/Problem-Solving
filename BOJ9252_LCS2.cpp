#include <iostream>
#include <string>
#include <stack>
using namespace std;
string s1, s2;
stack<char> s;
int dp[1001][1001];
int main() {
	int l1, l2;
	cin >> s1 >> s2;
	l1 = s1.size(), l2 = s2.size();
	for (int i = 1; i < l1+1; i++) {
		for (int j = 1; j < l2+1; j++) {
			if (s1[i-1] == s2[j-1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	cout << dp[l1][l2] << '\n';
	while (l1-1>=0 && l2-1>=0) {
		if (s1[l1 - 1] == s2[l2 - 1]) {
			s.push(s1[l1 - 1]);
			l1--;
			l2--;
		}
		else {
			if (dp[l1][l2] == dp[l1 - 1][l2])
				l1--;
			else
				l2--;
		}
	}
	while (!s.empty()) {
		cout << s.top();
		s.pop();
	}
	return 0;
}
