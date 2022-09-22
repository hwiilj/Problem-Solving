/*
  무난한 DP 문제
*/
#include <cstdio>
int arr[1000][3];
int dp[1000][3];
int main() {
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d %d", &arr[i][0], &arr[i][1], &arr[i][2]);
	}
	for (int i = 0; i < 3; i++)
		dp[0][i] = arr[0][i];
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				if (j == k)continue;
				if(!dp[i][j] || dp[i][j] > dp[i-1][k]) dp[i][j] = dp[i-1][k];
			}
			dp[i][j] += arr[i][j];
		}
	}
	int ans = 0;
	for (int i = 0; i < 3; i++) {
		if (ans == 0 || ans > dp[N - 1][i])ans = dp[N - 1][i];
	}
	printf("%d", ans);
	return 0;
}
