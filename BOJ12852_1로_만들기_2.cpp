#include <cstdio>
int arr[1000001];
int record[1000001];

int main() {
	int N;
	scanf("%d", &N);

	for (int i = 2; i <= N; i++) {
		arr[i] = arr[i - 1] + 1;
		if (i%2==0 && arr[i / 2] + 1< arr[i])arr[i] = arr[i / 2] + 1;
		if (i%3==0 && arr[i / 3] + 1< arr[i])arr[i] = arr[i / 3] + 1;
	}
	printf("%d\n", arr[N]);
	while (1) {
		printf("%d ", N);
		if (N == 1)break;
		if (N % 2 == 0 && arr[N / 2] == arr[N] - 1)N /= 2;
		else if (N % 3 == 0 && arr[N / 3] == arr[N] - 1)N /= 3;
		else N--;
	}
	return 0;
}
