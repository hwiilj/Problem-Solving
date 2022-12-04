/*
* BFS + Disjoint Set
*/
#include <iostream>
#include <queue>
using namespace std;
#define x first
#define y second
int arr[2001][2001];
int visited[2001][2001];
int N, K, S;
int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
pair<int, int>root[2001][2001];
queue<pair<int, int>> q;
pair<int, int> find(pair<int, int> n) {
	if (root[n.x][n.y].x == n.x && root[n.x][n.y].y == n.y) return root[n.x][n.y];
	else
		return root[n.x][n.y] = find(root[n.x][n.y]);
}
void merge(pair<int, int> a, pair<int, int> b) {
	a = find(a), b = find(b);
	if (a == b) return;
	if(arr[a.x][a.y]==1 && arr[b.x][b.y]==1)S--;
	if(arr[a.x][a.y]==1)
		root[b.x][b.y] = a;
	else if(arr[b.x][b.y]==1)
		root[a.x][a.y] = b;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> K;
	int cx, cy;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			root[i][j] = { i,j };
		}
	}
	for (int i = 0; i < K; i++) {
		cin >> cx >> cy;
		arr[cx][cy] = 1;
		q.push({ cx,cy } );
	}
	S = K;
	while (!q.empty()) {
		int cx = q.front().x, cy = q.front().y;
		q.pop();
		visited[cx][cy] = 1;
		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i], ny = cy + dy[i];
			if (!(nx > 0 && nx <= N && ny > 0 && ny <= N))continue;
			if (visited[nx][ny]) {            
        // 이 부분을 arr[nx][ny]로 작성했다가 오답 원인을 찾는데 애를 먹었다. 
        // 만약 비문명 지역이 q.pop이 되지 않은 상태에서 서로 접촉하면 비문명끼리 propagate되므로 문제가 생긴다.
				merge({ nx, ny }, { cx, cy });
				if (S == 1) {
					cout << arr[cx][cy] - 1 << "\n";
					break;
				}
				continue;
			}
			if (arr[nx][ny])continue;
			arr[nx][ny] = arr[cx][cy] + 1;
			q.push({ nx, ny });
		}
		if (S == 1)
			break;
	}
	return 0;
}
