/*
  BFS 완탐으로 clear.
  가지치기를 좀 하긴 했는데, 10만 아래라서 큰 효과는 없었다.
*/
#include <cstdio>
#include <queue>
using namespace std;
typedef struct {
	int loc;
	int t;
}node;

queue<node> q;
int arr[100001];
int main() {
	int N, K;
	scanf("%d %d", &N, &K);
	for (register int i = 0; i <= 100000; i++)
		arr[i] = 10000000;
	q.push({ N, 0 });
	arr[N] = 0;
	while (!q.empty()) {
		node t = q.front();
		q.pop();
		if (t.loc == K) break;
		if (t.loc * 2 <= K*2 && t.loc * 2 <= 100000 && arr[t.loc * 2] > t.t + 1) {
			q.push({ t.loc * 2, t.t + 1 });
			arr[t.loc * 2] = t.t + 1;
		}
		if (t.loc - 1 >= 0 && arr[t.loc - 1] > t.t + 1) {
			q.push({ t.loc - 1,t.t + 1 });
			arr[t.loc - 1] = t.t + 1;
		}
		if (t.loc + 1 <= K && arr[t.loc + 1] > t.t + 1) {
			q.push({ t.loc + 1,t.t + 1 });
			arr[t.loc + 1] = t.t + 1;
		}
	}
	printf("%d", arr[K]);

	return 0;
}
