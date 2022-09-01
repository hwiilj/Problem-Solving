/* Idea
1. 두 구간이 떨어진 경우
각각 꺠졌을 때 맞는 위치를 찾아서 뒤집으면 됨.

2. 두 구간이 겹쳐있는 경우
앞뒤 순서 상관있음. 
이런 경우 뒤에서 먼저 찾아야함.

1234567890
1)
1 2 6 5 4 3 7 8 9 0(뒤)
1 2 6 5 8 7 3 4 9 0(뒤)

2)
1 2 3 4 8 7 6 5 9 0(앞)
1 2 7 8 4 3 6 5 9 0(앞)

1234786590(앞x)
12


12785634

3. 하나가 하나를 포함한 경우
앞뒤 순서 상관없음. 1번처럼 두번 찾아서 뒤집으면 됨.

4. 두개가 딱 붙은 경우
이건 하나를 찾고 그냥 나머지는 아무것도 안하는 걸로 퉁치면 됨.
*/

#include <cstdio>
int N;
int farr[10001], barr[10001];
int ans[2][2];
int cnt = 0;
void freverse(int s, int e) {
	register int i, tmp;
	int m = (s + e) / 2;
	for (i = s; i <= m; i++) {
		tmp = farr[i];
		farr[i] = farr[e - (i - s)];
		farr[e - (i - s)] = tmp;
	}
}
void breverse(int s, int e) {
	register int i, tmp;
	int m = (s + e) / 2;
	for (i = s; i <= m; i++) {
		tmp = barr[i];
		barr[i] = barr[e - (i - s)];
		barr[e - (i - s)] = tmp;
	}
}
int found(int arr[10001]) {
	register int i;
	for (i = 1; i <= N; i++)
		if (arr[i] != i)
			return -1;
	return 0;
}
int front() {
	register int i, j;
	for (i = 1; i <= N &&cnt<2; i++) {
		if (farr[i] != i) {
			for (j = i + 1; j <= N; j++) {
				if (farr[j] == i) {
					freverse(i, j);
					ans[cnt][0] = i, ans[cnt][1] = j;
					cnt++;
					break;
				}
			}
		}
	}
	if (found(farr) == 0) {
		for (i = 0; i < cnt; i++)
			printf("%d %d\n", ans[i][0], ans[i][1]);
		while (cnt < 2) {
			printf("1 1\n");
			cnt++;
		}
		return 0;
	}
	else
		return -1;
}
int back() {
	register int i, j;
	for (i = N; i >= 1 && cnt<2; i--) {
		if (barr[i] != i) {
			for (j = i - 1; j >= 1; j--) {
				if (barr[j] == i) {
					breverse(j, i);
					ans[cnt][0] = j, ans[cnt][1] = i;
					cnt++;
					break;
				}
			}
		}
	}
	if (found(barr) == 0) {
		for (i = 0; i < cnt; i++)
			printf("%d %d\n", ans[i][0], ans[i][1]);
		while (cnt < 2) {
			printf("1 1\n");
			cnt++;
		}
		return 0;
	}
	else
		return -1;
}
int main()
{
	register int i,j;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) {
		scanf("%d", &farr[i]);
		barr[i] = farr[i];
	}

	if (front() < 0) {
		cnt = 0;
		back();
	}
	return 0;
}
