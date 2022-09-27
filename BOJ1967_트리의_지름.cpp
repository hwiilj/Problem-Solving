/*
  leaf노드를 찾아 leaf노드에서부터 다른 leaf노드까지 길이중 가장 긴 것을 찾았다.
  임의의 점에서 가장 먼 점이 무조건 지름의 끝 부분이라는데 그런 방법은 떠올리지 못했다.
*/
#include <iostream>
#include <vector>
using namespace std;
int index[10001];
int leaf_check[10001];
int leaf[10001];
int leaf_cnt = 0;
struct node {
	int dst;
	int dist;
};
vector <struct node> v[10001];
int ans = 0;
int visited[10001];
void dfs(int c, int d) {
	visited[c] = 1;
	if (d > ans)ans = d;
	
	for (int i = 0; i<v[c].size(); i++) {
		if (!visited[v[c][i].dst])
			dfs(v[c][i].dst, d + v[c][i].dist);
	}
}
int main() {
	int n, a, b, c;
	cin >> n;
	for (int i = 0; i < n-1; i++) {
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
		if (!leaf_check[a]) leaf_check[a] = 1;
		
	}
	for (int i = 1; i <= n; i++) {
		if (!leaf_check[i])leaf[leaf_cnt++] = i;
	}
	for (int i = 0; i < leaf_cnt; i++) {
		for (int j = 0; j < n; j++)
			visited[j]=0;
		dfs(leaf[i], 0);
	}
	cout << ans << '\n';

	return 0;
}
