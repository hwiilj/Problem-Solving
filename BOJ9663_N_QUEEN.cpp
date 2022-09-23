/*
  놓은 Queen을 직접 draw해서 못 놓는 곳을 판단하는
  비효율적인 짓을 해서 시간초과 떴던 것을 개선하였다.
*/  
#include <cstdio>
int N;
int arr[15][15];
int q[15][2];
int ans = 0;
int check(int x, int y) {
	for (int i = 0; i < x; i++) {
		if (q[i][1] == y) return -1;
		if (q[i][0] - q[i][1] == x - y)return -1;
		if (q[i][0] + q[i][1] == x + y)return -1;
	}
	return 0;
}
void search(int d) {
	if (d == N - 1) {
		ans++;
		return;
	}
	for (int i = 0; i < N; i++) {
		if (check(d + 1, i))continue;
		q[d+1][0] = d+1;
		q[d+1][1] = i;
		search(d+1);
	}
}
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		q[0][0] = 0;
		q[0][1] = i;
		search(0);
	}
	printf("%d", ans);
	return 0;
}
