/*
  BFS라고 생각하고 풀었는데
  백준 내 카테고리는 DP로 되어있다.
*/
#include <cstdio>
#include <queue>
using namespace std;
struct node {
	int index;
	int cnt;
};
queue<struct node> q;
int arr[1001];
int check[1001];
int main() {
	int N, ans = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
		check[i] = -1;
	}
	for (int i = 0; i < N; i++) {
		check[i] = 1;
		q.push({ i,1 });
	}

	while (!q.empty()) {
		struct node n = q.front();
		q.pop();
		if (n.index == N-1) {
			continue;
		}
		for (int j = n.index+1; j < N; j++) {
			if (arr[j] > arr[n.index] && (check[j] == -1 || check[j] < n.cnt + 1)) {
				check[j] = n.cnt + 1;
				q.push({ j, n.cnt + 1 });
			}
		}
	}
	for (int i = 0; i < N; i++) {
		if (ans < check[i])ans = check[i];
	}
	printf("%d", ans);
	return 0;
}
