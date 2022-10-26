/*
* LCA를 구한다.
* lca까지 올라가며 최소값,최대값을 구한다.
* -> 쿼리가 10만이므로 O(k)가 나오면 안된다. O(logK)
* -> Seg tree? 양쪽 노드 모두를 포함하게 되므로 불가능.
* -> Sol) parent 배열말고 min, max도 lca의 parent와 동일하게 전처리한다.
*/
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
int N, K;
#define MAX_VAL (1000001)
map<int,int> v[100001];
int visited[100001];
int parent[100001][20];
int level[100001];
int min_p[100001][20], max_p[100001][20];
int lca_min, lca_max;
void dfs(int n, int l) {
	visited[n] = 1;
	level[n] = l;
	for (auto a : v[n]) {
		if (visited[a.first])continue;
		parent[a.first][0] = n;

		dfs(a.first, l+1);
	}
}

void get_lca(int a, int b) {
	lca_min = MAX_VAL, lca_max = 0;
	if (level[a] < level[b])a ^= b ^= a ^= b;
	int diff = level[a] - level[b];
	for (int i = 0; diff > 0; i++) {
		if (diff & 0x1) {
			lca_min = min(lca_min, min_p[a][i]);
			lca_max = max(lca_max, max_p[a][i]);
			a = parent[a][i];
		}
		diff >>= 1;
	}
	if (a == b)return;
	for (int i = 19; i >= 0; i--) {
		if (parent[a][i] != parent[b][i]) {
			lca_min = min(lca_min, min_p[a][i]);
			lca_min = min(lca_min, min_p[b][i]);
			lca_max = max(lca_max, max_p[a][i]);
			lca_max = max(lca_max, max_p[b][i]);
			a = parent[a][i], b = parent[b][i];
		}
	}
	lca_min =  min(lca_min, min_p[a][0]);
	lca_min = min(lca_min, min_p[b][0]);
	lca_max = max(lca_max, max_p[a][0]);
	lca_max = max(lca_max, max_p[b][0]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	int a, b, c;
	for (int i = 0; i < N-1; i++) {
		cin >> a >> b >> c;
		v[a][b] = c;
		v[b][a] = c;
	}
	dfs(1,1);
	for (int j = 1; j <= N; j++) {
		if(parent[j][0]==0){
			min_p[j][0] = 0;
			max_p[j][0] = 0;
		}
		else {
			min_p[j][0] = v[j][parent[j][0]];
			max_p[j][0] = v[j][parent[j][0]];
		}

	}
	for (int i = 1; i < 20; i++) {
		for (int j = 1; j <= N; j++) {
			parent[j][i] = parent[parent[j][i - 1]][i - 1];
			min_p[j][i] = min(min_p[j][i-1], min_p[parent[j][i - 1]][i - 1]);
			max_p[j][i] = max(max_p[j][i-1], max_p[parent[j][i - 1]][i - 1]);
		}
	}
	int K, D, E;
	cin >> K;
	for (int i = 0; i < K; i++) {
		cin >> D >> E;
		get_lca(D, E);
		cout << lca_min << " " << lca_max << '\n';
	}
	return 0;
}
