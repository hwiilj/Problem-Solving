/*
	삽입, 탐색 모두 선형이 나오면 안되는 문제.
	seg tree.
	leaf엔 영화 번호. 영화번호로 leaf번호에 대한 index table
	seg tree는 해당 번호사이에 몇 개 존재하는지.
*/
#include <iostream>
using namespace std;
int n, m;
int tree[800008];
int arr[200002];
int index[100001];
int update(int node, int s, int e, int i, int d) {
	if (i < s || e < i)return tree[node];
	if (s == i && i == e) return tree[node] += d;
	int m = (s + e)/2;
	return tree[node] = update(node * 2, s, m, i, d) + update(node * 2+1, m+1, e, i, d);
}
int search(int node, int s, int e, int l, int r) {
	if (l <= s && e <= r) return tree[node];
	if (r < s || e < l) return 0;
	int m = (s + e) / 2;
	return search(node * 2, s, m, l, r) + search(node * 2 + 1, m + 1, e, l, r);
}
int init(int node, int s, int e) {
	if (s == e) {
		return tree[node] = arr[s]>0;
	}
	int m = (s + e) / 2;
	return tree[node] = init(node * 2, s, m) + init(node * 2 + 1, m + 1, e);
}
void solve() {
	cin >> n >> m;
	int movie;
	for (int i = 0; i < 800008; i++) {
		tree[i] = 0;
	}
	for (int i = 0; i < 200002; i++)
		arr[i] = 0;
	for (int i = 0; i < 100001; i++)
		index[i] = 0;
	for (int i = 1; i <= n; i++) {
		arr[m+i] = i;
		index[i] = m + i;
	}
	init(1, 1, n +m);
	
	for (int i = 1; i <= m; i++) {
		cin >> movie;
		cout << search(1, 1, n + m, 1, index[movie] - 1) << " ";
		update(1, 1, n+m, index[movie], -1);
		update(1, 1, n+m, m-i, 1);
		index[movie] = m - i;
	}
	cout << '\n';
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--)solve();
	return 0;
}
