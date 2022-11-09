/*
* lazy propagation + euler
*/
#include <iostream>
#include <vector>
using namespace std;
#define ll long long
vector<int> v[500001];
ll arr[500001];
ll lazy[500001 * 4];
int N;
int S[500001], E[500001], visited[500001], cnt=0;
void lazy_update(int n, int s, int e) {
	if (lazy[n]) {
		if (s != e) {
			lazy[n * 2] += lazy[n];
			lazy[n * 2 + 1] += lazy[n];
			lazy[n] = 0;
		}
	}
}
void update(int n, int s, int e, int l, int r, int v) {
	lazy_update(n, s, e);
	if (s > r || e < l) return;
	if (l <= s && e <= r) {
		lazy[n] += v;
		lazy_update(n, s, e);
		return;
	}
	int m = (s + e) / 2;
	update(n * 2, s, m, l, r, v);
	update(n * 2 + 1, m + 1, e, l, r, v);
}
ll query(int n, int s, int e, int i) {
	lazy_update(n, s, e);
	if (s == e) {
		return lazy[n];
	}
	int m = (s + e) / 2;
	if (m >= i)
		return query(n * 2, s, m, i);
	else return query(n * 2 + 1, m + 1, e, i);
}
void dfs(int n) {
	S[n] = ++cnt;
	for (auto a : v[n]) {
		if (visited[a])continue;
		visited[a] = 1;
		dfs(a);
	}
	E[n] = cnt;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int M;
	cin >> N >> M;
	int a, b;
	char c;
	for (int i = 1; i <= N; i++) {
		if (i == 1)
			cin >> a;
		else {
			cin >> a >> b;
			v[b].push_back(i);
		}
		arr[i] = a;
	}
	dfs(1);
	for (int i = 0; i < M; i++) {
		cin >> c;
		if (c == 'p') {
			cin >> a >> b;
			if(S[a]<E[a])
				update(1, 1, N, S[a]+1, E[a], b);
		}
		else
		{
			cin >> a;
			cout << arr[a] + query(1, 1, N, S[a]) << '\n';
		}
	}
	return 0;
}
