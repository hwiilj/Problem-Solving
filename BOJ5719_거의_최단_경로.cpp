/*
* 1. 다익스트라로 최소비용 경로를 찾는다.
* 2. 해당 경로를 제거한다. 최소비용 경로가 여러개일 때가 문제.
* 3. 모든 경로를 다 가본다.
	-> 다익스트라를 최소비용일 때 멈추지말고 계속 진행, 최소비용을 초과하는 경로가 나오면 stop.
	-> X. 시간 초과.
  4. 나온 최소비용경로를 모두 제거해준다.
    -> 최소비용경로를 어디에 저장? 각 노드로 가는 최소 비용 배열을 통해
	-> X. 중단점에서는 최소가 아닌 경로가 있으므로 해당 방법으로 불가능. prev 배열을 사용.
  5. 다익스트라를 다시 돌린다.
*/
#include <iostream>
#include <map>
#include <queue>
#include <vector>
#define MAX_VAL (10000*1000+3)
using namespace std;
int N, M;
int S, D;
map<int, int> m[500];
vector<int> pr[500];
int w[500];
priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
void dijkstra() {
	pq.push({ 0,S });
	while (!pq.empty()) {
		pair<int, int>r = pq.top();
		pq.pop();
		if (w[r.second] < r.first)continue;
		if (r.second == D)continue;
		for (auto a : m[r.second]) {
			if (a.second == -1) continue;
			if (w[a.first] > r.first + a.second) {
				w[a.first] = r.first + a.second;
				pr[a.first].clear();
				pr[a.first].push_back(r.second);
				pq.push({ r.first + a.second, a.first });
			}
			else if (w[a.first] == r.first + a.second) {
				pr[a.first].push_back(r.second);
			}
		}
	}
}
void delete_dfs(int n) {
	if (n == S)return;
	for (auto a : pr[n]) {
		if (m[a][n]!=-1) {
			m[a][n] = -1;
			delete_dfs(a);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int U, V, P;

	while (1) {
		cin >> N >> M;
		if (N == 0 && M == 0)break;

		for (int i = 0; i < N; i++) {
			m[i].clear();
			pr[i].clear();
			w[i] = MAX_VAL;
		}

		cin >> S >> D;
		for (int i = 0; i < M; i++) {
			cin >> U >> V >> P;
			m[U][V] = P;
		}
		dijkstra();
		delete_dfs(D);

		for (int i = 0; i < N; i++) {
			w[i] = MAX_VAL;
		}
		dijkstra();

		if (w[D] == MAX_VAL)cout << "-1\n";
		else cout << w[D] << '\n';
	}
}
