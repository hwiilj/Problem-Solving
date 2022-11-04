/*
	merge sort tree
	m이 5000이므로
	O(n)으로도 TLE
	k번째 수 x를 찾아라
	-> x보다 작은 원소가 k개 미만 중 최대인 수
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
int arr[100001];
vector<int> tree[100001];
void init() {
	int t;
	for (int i = 1; i <= N; i++) {
		t = i;
		while (t <= N) {
			tree[t].push_back(arr[i]);
			t += t & -t;
		}
	}
}
int query(int l, int r, int k) {
	int s = -1e9, e = 1e9;
	int ret;
	while (s <= e) {
		int m = (s + e) / 2;
		int t = r, sum=0;
		while (t > 0) {
			sum += lower_bound(tree[t].begin(), tree[t].end(), m) - tree[t].begin();
			t -= t & -t;
		}
		t = l-1;
		while (t > 0) {
			sum -= lower_bound(tree[t].begin(), tree[t].end(), m) - tree[t].begin();
			t -= t & -t;
		}
		t = l;
		if (sum >= k) {
			e = m-1;
		}
		else {
			ret = m;
			s = m + 1;
		}
	}
	return ret;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int M, a, b, c;
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		cin >> arr[i];
	init();
	for (int i = 1; i <= N; i++) {
		sort(tree[i].begin(), tree[i].end());
	}
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b >> c;
		cout << query(a, b, c) << '\n';
	}
	return 0;
}
