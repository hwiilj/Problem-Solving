/*
  0-1 knapsack problem
  오랜만에 풀었더니 기억이 잘 안나 헤맸다.
*/
#include <cstdio>
int arr[100][2];
int dp[100][100000];
int main() {
	int N, K, ans = 0;
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &arr[i][0], &arr[i][1]);
	}
	dp[0][K] = 0;
	dp[0][K - arr[0][0]] = arr[0][1];
	for (int i = 1; i < N; i++) {
		for (int j = K; j >= 0; j--) {
			dp[i][j] = dp[i][j]< dp[i - 1][j]?dp[i-1][j]:dp[i][j];
			if(j>=arr[i][0])
				dp[i][j - arr[i][0]] = dp[i - 1][j] + arr[i][1];
		}
	}
	for (int j = K; j >= 0; j--) {
		ans = ans < dp[N - 1][j] ? dp[N - 1][j] : ans;
	}
	printf("%d", ans);
	return 0;
}
