/*
	LCA를 구해 각 거리를 더하면 끝나는 문제

	-> dfs를 완료 후에 parent를 업데이트해야 한다.
	->
*/
#include <iostream>
#include <vector>
using namespace std;
int N;
int parent[40001][20];
int level[40001];
int w[40001];
vector<pair<int, int>> v[40001];
void init(int n, int p) {
	parent[n][0] = p;
	level[n] = level[p] + 1;

	for (auto a : v[n]) {
		if (level[a.first] > 0)continue;
		w[a.first] = w[n] + a.second;
		init(a.first, n);
	}
}
int lca(int a, int b) {
	if (level[a] < level[b]) {
		swap(a, b);
	}
	if (level[a] != level[b]) {
		for (int i = 19; i >= 0; i--) {
			if (level[parent[a][i]] >= level[b])
				a = parent[a][i];
		}
	}
	if (a == b)return a;
	for (int i = 19; i >= 0; i--) {
		if (parent[a][i] != parent[b][i]) {
			a = parent[a][i];
			b = parent[b][i];
		}
	}
	return parent[a][0];
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int M, a, b, c;
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}
	init(1, 0);

	for (int i = 1; i < 20; i++) {
		for (int j = 1; j <= N; j++)
			parent[j][i] = parent[parent[j][i - 1]][i - 1];
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		int c = lca(a, b);
		cout << w[a] - w[c] + w[b] - w[c] << '\n';
	}

	return 0;
}
