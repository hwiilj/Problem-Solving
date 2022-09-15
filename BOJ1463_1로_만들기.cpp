/*
  DP는 떠올리기만 하면 푸는건 쉽다
*/
#include <cstdio>
int mem[1000001];
int main() {
	int N;
	scanf("%d", &N);
	for (int i = 2; i <= N; i++) {
		int best = 10000000;
		if (i % 2 == 0)best = mem[i / 2] + 1;
		if (i % 3 == 0)best = (best > mem[i / 3] + 1) ? mem[i / 3] + 1 : best;
		mem[i] = (best > mem[i - 1] + 1) ? mem[i - 1] + 1 : best;
	}
	printf("%d", mem[N]);
	return 0;
}
