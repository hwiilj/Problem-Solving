/*
  Segment Tree
*/
#include <iostream>
using namespace std;
long long tree[4000004];
long long arr[1000001];
long long init(int node, int start, int end) {
	if (start == end) {
		return tree[node] = arr[start];
	}
	int m = (start + end) / 2;
	return tree[node] = init(node * 2, start, m) +	init(node * 2 + 1, m + 1, end);
}
void update(int node, int start, int end, int idx, long long diff) {
	if (end<idx || start>idx) return;
	tree[node] += diff;
	if (start == end) return;
	int m = (start + end) / 2;
	update(node*2, start, m, idx, diff);
	update(node*2+1, m+1, end, idx, diff);
}
long long get_sum(int node, int start, int end, int left, int right) {
	if (end < left || right < start)return 0;
	if (left <= start && end <= right) return tree[node];
	int m = (start + end) / 2;
	return get_sum(node * 2, start, m, left, right) + get_sum(node * 2 + 1, m + 1, end, left, right);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N, M, K;
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	init(1, 1, N);
	long long a, b, c;
	for (int i = 0; i < M+K; i++) {
		cin >> a >> b >> c;
		if (a == 1) {
			update(1, 1, N, b, c - arr[b]);
			arr[b] = c;
		}
		else {
			cout << get_sum(1, 1, N, b, c) << '\n';
		}
	}
	return 0;
}
