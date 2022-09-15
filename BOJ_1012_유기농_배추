/* 단순 그래프 탐색 문제
   오답노트 : 방문 체크는 queue에서 pop할 때가 아닌 push 직후에 해야 한다.
   그렇지 않으면, 중복해서 같은 노드를 반복하게 된다.
*/

#include <cstdio>
#include <queue>
using namespace std;
typedef struct {
	int x, y;
}cor;
queue<cor> q;
int M, N, K;
int arr[51][51];
int main() {
	int T, X, Y, ans;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) {
		ans = 0;
		scanf("%d %d %d", &M, &N, &K);
		for (int i = 0; i < M; i++)
			for (int j = 0; j < N; j++)
				arr[i][j] = 0;
		for (int i = 0; i < K; i++) {
			scanf("%d %d", &X, &Y);
			arr[X][Y] = 1;
		}
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				if (arr[i][j] == 1) {

					ans++;
					q.push({ i,j });
					arr[i][j] = 0;
					while (!q.empty()) {
						cor t = q.front();
						q.pop();
						if (t.x + 1 < M && arr[t.x + 1][t.y]) {
							q.push({ t.x + 1, t.y });
							arr[t.x + 1][t.y] = 0;
						}
						if (t.y + 1 < N && arr[t.x][t.y + 1]) {
							q.push({ t.x, t.y + 1 });
							arr[t.x][t.y + 1] = 0;
						}
						if (t.x - 1 >= 0 && arr[t.x - 1][t.y]) {
							q.push({ t.x - 1, t.y });
							arr[t.x - 1][t.y] = 0;
						}
						if (t.y - 1 >= 0 && arr[t.x][t.y - 1]) {
							q.push({ t.x, t.y - 1 });
							arr[t.x][t.y - 1] = 0;
						}
					}
				}
			}
		}
		while(!q.empty())q.pop();
		printf("%d\n", ans);
	}
	return 0;
}
