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

/*
	N개에 대한 dp 배열을 굳이 만들필요 있나 해서
	dp 배열을 한개로 뒀는데, 이상하게 틀렸다.
	한참 헤매다 보니, for j에서 방향을 반대로 해서 중복되는게 문제인 것을 발견했다.
<오답 코드>

#include <cstdio>
int arr[100][2];
int dp[100001];
int main() {
	int N, K, ans = 0;
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &arr[i][0], &arr[i][1]);
	}
	for (int i = 0; i < N; i++) {
		for (int j = K; j >= arr[i][0]; j--) {
			dp[j - arr[i][0]] = dp[j - arr[i][0]] < dp[j] + arr[i][1] ? dp[j] + arr[i][1] : dp[j - arr[i][0]];
		}
	}
	for (int j = K; j >= 0; j--) {
		ans = ans < dp[j] ? dp[j] : ans;
	}
	printf("%d", dp[0]);
	return 0;
}
*/
