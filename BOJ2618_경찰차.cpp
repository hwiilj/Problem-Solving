/*
* dp[N][1~N-1] -> 1,2번 경찰차의 위치
* dp[N][y] =  dp[N-1][y] + dist(N-1,N) (y:0~N-2)
* dp[N][N-1] = dp[x][N-1] + dist(N, x) x:0~N-2
* dp[x][N] = dp[x][N] + dist(N-1,N) (x:0~n-2)
* dp[N-1][N] = dp[N-1][x] + dist(x,N) (x:0~N-2)
* -> 이 방법은 현재까지 이동 거리. 하지만, 앞으로 가야할 거리로 풀면 더 간단하고 빠르게 풀 수 있음.
*/
#include <iostream>
using namespace std;
#define MAX_VAL (2000 * 1000 * 10)
int N, W;
int arr[1001][2];
int dp[1001][1001];
int pol1[2], pol2[2];
int ans_arr[1001];
inline int dist(int a[2], int b[2]) {
	int x = a[0] - b[0];
	int y = a[1] - b[1];
	if (x < 0)x *= -1;
	if (y < 0)y *= -1;
	return x + y;
}
void dfs(int p1, int p2) {
	if (p1 <= 1 && p2 <= 1) {
		if (p2 == 1)
			ans_arr[p2] = 2;
		if (p1 == 1)
			ans_arr[p1] = 1;
		return;
	}
	if (p1 - 1 == p2) {
		for (int i = 0; i <= p2 - 1; i++) {
			int x = i == 0 ? dist(pol1, arr[p1]) : dist(arr[i], arr[p1]);
			if (dp[p1][p2] == dp[i][p2] + x) {
				ans_arr[p1] = 1;
				dfs(i, p2);
			}
		}
	}
	else if (p1 == p2 - 1) {
		for (int i = 0; i <= p2 - 1; i++) {
			int x = i == 0 ? dist(pol2, arr[p2]) : dist(arr[i], arr[p2]);
			if (dp[p1][p2] == dp[p1][i] + x) {
				ans_arr[p2] = 2;
				dfs(p1, i);
			}
		}
	}
	else if (p1 < p2) {
		if (dp[p1][p2] == dp[p1][p2 - 1] + dist(arr[p2 - 1], arr[p2])) {
			ans_arr[p2] = 2;
			dfs(p1, p2 - 1);
		}
	}
	else if (p1 > p2) {
		if (dp[p1][p2] == dp[p1 - 1][p2] + dist(arr[p1 - 1], arr[p1])) {
			ans_arr[p1] = 1;
			dfs(p1 - 1, p2);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> W;
	for (int i = 1; i <= W; i++) {
		cin >> arr[i][0] >> arr[i][1];
	}
	for (int i = 0; i <= W; i++) {
		for (int j = 0; j <= W; j++) {
			dp[i][j] = MAX_VAL;
		}
	}
	pol1[0] = 1, pol1[1] = 1;
	pol2[0] = N, pol2[1] = N;
	dp[1][0] = dist(arr[1], pol1);
	dp[0][1] = dist(arr[1], pol2);
	for (int i = 2; i <= W; i++) {
		for (int j = 0; j <= i - 2; j++) {
			dp[i][j] = min(dp[i][j],dp[i - 1][j]+ dist(arr[i],arr[i-1]));
		}
		for (int j = 0; j <= i - 2; j++) {
			int d = j == 0 ? dist(pol1, arr[i]) : dist(arr[j], arr[i]);
			dp[i][i - 1] = min(dp[i][i - 1], dp[j][i - 1] + d);
		}
		for (int j = 0; j <= i - 2; j++) {
			dp[j][i] = min(dp[j][i], dp[j][i-1] + dist(arr[i], arr[i - 1]));
		}
		for (int j = 0; j <= i - 2; j++) {
			int d = j == 0 ? dist(pol2, arr[i]) : dist(arr[j], arr[i]);
			dp[i-1][i] = min(dp[i-1][i], dp[i-1][j] + d);
		}
	}
	int ans = MAX_VAL, ans_ptr[2];
	for (int i = 0; i <= W - 1; i++) {
		if (dp[i][W] < ans) {
			ans = dp[i][W];
			ans_ptr[0] = i, ans_ptr[1] = W;
		}
		if (dp[W][i] < ans) {
			ans = dp[W][i];
			ans_ptr[0] = W, ans_ptr[1] = i;
		}
	}
	dfs(ans_ptr[0], ans_ptr[1]);


	cout << ans << '\n';
	for (int i = 1; i <= W; i++)
		cout << ans_arr[i] << '\n';
	return 0;
}
