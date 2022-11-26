/*
	dijkstra k++
	가지치기의 최적화 k번째까지의 경로까지 미리 cut <- PQ를 써야 가능
*/
#include <iostream>
#include <queue>
using namespace std;
int n, k;
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
vector<pair<int,int>>q[1001];
priority_queue<int>ans[1001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int m, a, b, c;
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		q[a].push_back({ c,b });
	}
	pq.push({ 0,1 });
	ans[1].push(0);
	while (!pq.empty()) {
		int w = pq.top().first, n = pq.top().second;
		pq.pop();
		if (ans[n].top() < w)continue;
		
		for (auto a : q[n]) {
			if (ans[a.second].size() == k) {
				if (ans[a.second].top() > a.first + w) {
					ans[a.second].pop();
					ans[a.second].push(a.first + w);
					pq.push({ a.first + w, a.second });
				}
			}
			else {
				ans[a.second].push(a.first + w);
				pq.push({ a.first + w, a.second });
			}			
		}
	}
	for (int i = 1; i <= n; i++) {
		if(ans[i].size()==k)
			cout << ans[i].top() << "\n";
		else
			cout << "-1\n";
	}
	return 0;
}
