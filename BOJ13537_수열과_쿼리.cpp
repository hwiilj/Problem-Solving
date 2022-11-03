/*
* Fenwick + merge sort tree
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
int arr[100001];
vector<int> tree[100001];
void init() {
	for (int i = 1; i <= N; i++) {
		int t = i;
		while (t <= N) {
			tree[t].push_back(arr[i]);
			t += t & -t;
		}
	}
	for (int i = 1; i <= N; i++) {
		sort(tree[i].begin(), tree[i].end());
	}
}
int upper_bound(vector<int> &a, int k) {
	int s = 0, e = a.size() - 1;
	int m = (s + e) / 2;
	int ret = a.size();
	while (s <= e) {
		m = (s + e) / 2;
		if (a[m] > k) {
			ret = m;
			e = m-1;
		}
		else {
			s = m + 1;
		}
	}
	return ret;
}
int query(int i, int j, int k) {
	int r=0, l=0;
	while (j > 0) {
		r += tree[j].size() - upper_bound(tree[j], k);
		j -= j & -j;
	}
	while (i > 0) {
		l += tree[i].size() - upper_bound(tree[i], k);
		i -= i & -i;
	}
	return r - l;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int M, s, e, k;
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> arr[i];
	init();
	cin >> M;
	for (int i = 1; i <= M; i++) {
		cin >> s >> e >> k;
		cout << query(s-1, e, k) << '\n';
	}

}
