/*
  value 범위가 커서 O(n)은 불가능.
  O(logn)으로 정렬, 탐색으로 구현.
  값 중첩은 prefix-sum으로 처리.
*/
#include <cstdio>
int N;
int arr[1000000];
int sorted[1000000];
int sorted_count[1000000];
int tmp[1000000];
int ans;
void m_sort(int s, int e) {
	int m = (s + e) / 2;
	int l = s, r = m + 1, t = s;
	if (!(s < e))return;
	m_sort(s, m);
	m_sort(m + 1, e);
	while (l <= m && r <= e) tmp[t++] = sorted[l] > sorted[r] ? sorted[r++] : sorted[l++];
	while (l <= m) tmp[t++] = sorted[l++];
	while (r <= e) tmp[t++] = sorted[r++];
	for (int i = s; i <= e; i++) {
		sorted[i] = tmp[i];
	}
}
void search(int s, int e, int val) {
	int m = (s + e) / 2;
	if (!(s <= e)) return;
	if (sorted[m] >= val) {
		search(s, m-1, val);
	}
	else {
		ans = m;
		search(m + 1, e, val);
	}
}
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
		sorted[i] = arr[i];
	}
	m_sort(0, N - 1);
	sorted_count[0] = 1;
	for (int i = 1; i < N; i++) {
		sorted_count[i] = sorted[i] == sorted[i - 1] ? sorted_count[i - 1] : sorted_count[i - 1] + 1;
	}
	for (int i = 0; i < N; i++) {
		ans = -1;
		search(0, N - 1, arr[i]);
		printf("%d ", ans==-1?0:sorted_count[ans]);
	}
	return 0;
}
