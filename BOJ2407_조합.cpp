/*
  오랜만에 큰 수 사칙연산 구현
*/
#include <cstdio>
int main() {
	int n, m;
	int s[100], r[100] = { 0 };
	for (int i = 0; i < 100; i++)s[i] = 0;
	scanf("%d %d", &n, &m);
	s[0] = 1;
	for (int i = 1; i <= m; i++) {
		s[0] *= n;
		for (int j = 1; j < 100; j++) {
			s[j] *= n;
			s[j] += s[j - 1] / 10;
			s[j - 1] %= 10;
		}
		n--;
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 100 - 1; j > 0; j--) {
			s[j] += r[j];
			r[j - 1] = s[j] % i * 10;
			s[j] /= i;
		}
		s[0] += r[0];
		s[0] /= i;
	}
	int flag = 0;
	for (int j = 100 - 1; j >= 0; j--) {
		if (s[j] != 0) flag = 1;
		if (!flag) continue;
		printf("%d", s[j]);
	}
	return 0;
}
