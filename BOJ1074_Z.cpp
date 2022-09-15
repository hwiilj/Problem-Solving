/*
  Divide and Conquer 문제
  완전 탐색하면 시간초과가 나오고,
  해당 범위가 아니면 가지치기를 적용하면 된다.
*/

#include <cstdio>
int ans=-1, cnt = 0;
int N, r, c;
void search(int x, int y, int d) {
	if (d == 0) {
		if (x == r && y == c) ans = cnt;
		cnt++;
		return;
	}
	if (x <= r && r < x + d && y <= c && c <= y + d)
		search(x, y, d >> 1);
	else cnt += d * d;
	if (x <= r && r < x + d && y + d <= c && c < y + d * 2) {
		search(x, y + d, d >> 1);
	}
	else
		cnt += d * d;
	if (x + d <= r && r < x + d * 2 && y <= c && c <= y + d)
		search(x + d, y, d >> 1);
	else
		cnt += d * d;
	if (x + d <= r && r < x + d * 2 && y + d <= c && c < y + d * 2)
		search(x + d, y + d, d >> 1);
	else
		cnt += d * d;
}
int main() {
	scanf("%d %d %d", &N, &r, &c);
	search(0, 0, 1<<(N-1));
	printf("%d", ans);
	return 0;
}
