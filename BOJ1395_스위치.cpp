/*
* 단순 segtree로 구현. reverse를 전체 개수 - 현재 count로 계산
* -> TLE. update 시 O(nlogn) 이므로.
* -> lazy propagation 적용.
*/
#include <iostream>

using namespace std;
int N;
int tree[400000];
int lazy[400000];
void lazy_update(int n, int s, int e) {
	if (lazy[n]) {
		lazy[n] = 0;
		tree[n] = e - s + 1 - tree[n];
		if (s != e) {
			lazy[n * 2] = 1 - lazy[n * 2];
			lazy[n * 2 + 1] = 1 - lazy[n * 2 + 1];
		}
	}
}
int update(int node, int s, int e, int l, int r) {
	lazy_update(node, s, e);
	if (s > r || e < l)return tree[node];
	if (l <= s && e <= r) {
		lazy[node] = 1 - lazy[node];
		lazy_update(node, s, e);
		return tree[node];
	}
	int m = (s + e) / 2;
	
	return tree[node] = update(node * 2, s, m, l, r) + update(node * 2 + 1, m + 1, e, l, r);
}
int query(int node, int s, int e, int l, int r) {
	if (s > r || e < l) return 0;
	lazy_update(node, s, e);
	if (l <= s && e <= r)
		return tree[node];
	int m = (s + e) / 2;
	return query(node * 2, s, m, l, r) + query(node * 2 + 1, m + 1, e, l, r);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int M, O, S, T;;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> O >> S >> T;
		if (O == 0) {
			update(1, 0, N - 1, S - 1, T - 1);
		}
		else {
			cout << query(1, 0, N - 1, S-1, T-1) << '\n';
		}
	}
	return 0;
}
