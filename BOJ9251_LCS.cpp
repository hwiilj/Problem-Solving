/*
  되게 오랜만에 본 LCS 문제
  기억이 안나니 푸는데 한참 걸렸다.
*/
#include <iostream>
#include <string>
using namespace std;
int dp[1000][1000];
int main() {
	string a, b;
	cin >> a >> b;
	int alen = a.length(), blen = b.length();
	int l, r;
	for (int i = 0; i < alen; i++) {
		for (int j = 0; j < blen; j++) {
			if (a[i] == b[j]) {
				if (i != 0 && j != 0)
					dp[i][j] = dp[i - 1][j - 1] + 1;
				else
					dp[i][j] = 1;
			}
			else {
				if (i == 0)l = 0;
				else l = dp[i - 1][j];
				if (j == 0)r = 0;
				else r = dp[i][j - 1];

				dp[i][j] = l < r ? r : l;
			}
		}
	}
	cout << dp[alen - 1][blen - 1];
	return 0;
}
