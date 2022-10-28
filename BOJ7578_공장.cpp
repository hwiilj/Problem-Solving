/*
* 케이블이 교차하는 조건
* A[x] < A[y] && B[x] > B[y]
* 개수를 세려면 나보다 오른쪽에 있는 것들이
* 매칭된 B열이 나보다 왼쪽이면 된다.
* 1<N<500000, query에 log n -> tree 사용.
* 나보다 작은 것이 몇개인지 아는 것은 쉬움.
* 그러나, 나보다 작은 것이 가지고 있는 값의 비교는?
* 정렬하여 순서대로 seg tree에 삽입하면, 현재 들어간 값들은 나보다 작은 것들만 들어있음.
* 즉, 가지고 있는 값을 비교 가능하다.
*/
#include <iostream>
using namespace std;
int arr[500000];
int brr[500000];
int index[1000001];
int tree[4000004];
int get_cnt(int node, int s, int e, int l, int r) {
	if (r < s || e < l)return 0;
	else if(l<=s && e<= r) return tree[node];
	int m = (s + e) >> 1;
	return get_cnt(node * 2, s, m, l, r) + get_cnt(node * 2 + 1, m + 1, e, l, r);
}
void update(int node, int s, int e, int index, int val) {
	if (e < index || s > index)return;
	tree[node] += val;
	if (s == e) return;
	int m = (s + e) >> 1;
	update(node * 2, s, m, index, val);
	update(node * 2 + 1, m + 1, e, index, val);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N;
	cin >> N;
	unsigned long long ans = 0;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> brr[i];
		index[brr[i]] = i;
	}
	for (int i = 0; i < N; i++) {
		ans += get_cnt(1, 0, N - 1, index[arr[i]] + 1, N-1);
		update(1, 0, N - 1, index[arr[i]], 1);
	}
	cout << ans;
}
