/*
  다익스트라처럼 풀면 clear
  priority_queue를 안 써서 느렸을 수 있는데 pass했다.
*/
#include <cstdio>
#include <queue>
using namespace std;
int visit[100001];
struct node {
	int x;
	int t;
};
queue<struct node> q;
int main() {
	int N, K;
	int ans = 1000000;
	struct node r;
	scanf("%d %d", &N, &K);
	for (int i = 0; i <= 100000; i++)visit[i] = -1;
	q.push({ N, 0 });
	while (!q.empty()) {
		r = q.front();
		q.pop();
		if (r.x == K) {
			ans = ans > r.t ? r.t : ans;
		}
		if (r.x - 1 >=0 && (visit[r.x-1]==-1 || visit[r.x-1] > r.t+1)) {
			q.push({ r.x - 1, r.t + 1 });
			visit[r.x - 1] = r.t + 1;
		}
		if (r.x + 1 <= K*2 && r.x+1 <=100000 && (visit[r.x+1]==-1 || visit[r.x+1] > r.t+1)) {
			q.push({ r.x + 1, r.t + 1 });
			visit[r.x + 1] = r.t + 1;
		}
		if (r.x * 2 <= K * 2 && r.x*2<=100000 && (visit[r.x *2]==-1 || visit[r.x *2] > r.t)) {
			q.push({ r.x * 2, r.t });
			visit[r.x * 2] = r.t;
		}
	}
	printf("%d", ans);
	return 0;
}
