/*
  Topology sort
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int depth[1001];
int weigh[1001];
int start[1001];
vector<int> v[1001];
queue<int> q;
int N, K;
void solve() {
	int s, d, dst;
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		cin >> weigh[i];
		depth[i] = 0;
		start[i] = -1;
		v[i].clear();
	}
	for (int i = 1; i <= K; i++) {
		cin >> s >> d;
		v[s].push_back(d);
		depth[d]++;
	}
	for (int i = 1; i <= N; i++) {
		if (!depth[i]) {
			start[i] = 0;
			q.push(i);
		}
	}
	while (!q.empty()) {
		int r = q.front();
		q.pop();
		for (int i = 0; i < v[r].size(); i++) {
			if (!(--depth[v[r][i]])) {
				q.push(v[r][i]);
			}
			start[v[r][i]] = max(start[v[r][i]], start[r] + weigh[r]);
		}
	}
	cin >> dst;
	cout << start[dst] + weigh[dst] << '\n';
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) solve();
	return 0;
}
