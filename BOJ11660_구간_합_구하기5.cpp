/*
  DP : printf문 점화식이 핵심.
  prefix sum 구할 때, 입력받음과 동시에 누적합을 구해서 좀 더 최적화할 수 있다.
*/
#include <cstdio>
int N, M;
int arr[1025][1025];
int sum[1025][1025];
int main() {
	int x1, y1, x2, y2;
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 2; j <= N; j++) {
			arr[i][j] += arr[i][j - 1];
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 2; j <= N; j++) {
			arr[j][i] += arr[j - 1][i];
		}
	}
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d %d", &x1,&y1, &x2, &y2);
		printf("%d\n", arr[x2][y2] - arr[x1 - 1][y2] - arr[x2][y1 - 1] + arr[x1 - 1][y1 - 1]);
	}
	return 0;
}
