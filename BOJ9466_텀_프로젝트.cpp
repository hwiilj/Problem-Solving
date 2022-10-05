/*
	Union-Find
	연결하려는 대상이 나랑 parent가 같으면 team
*/
#include <iostream>
using namespace std;
int arr[100001];
int parent[100001];
int find(int n) {
	if (parent[n] == n) return n;
	else return parent[n] = find(parent[n]);
}
void merge(int a, int b) {
	a = find(a);
	b = find(b);
	parent[b] = a;
}
void solve() {
	int n;
	int ans;
	cin >> n;
	ans = n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		parent[i] = i;
	}

	for (int i = 1; i <= n; i++) {
		int d = arr[i];
		if (find(d) != find(i)) {
			merge(d, i);
		}
		else {
			int t = i;
			while (1) {
				ans--;
				t = arr[t];
				if (t == i)break;
			}
		}
	}
	cout << ans << '\n';
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;
	while (T--) solve();

	return 0;
}
