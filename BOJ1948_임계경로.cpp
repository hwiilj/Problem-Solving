/*
* 1. 일방통행, no cycle
* 2. 모두 만나는 시간 : 모든 경로 중 가장 긴 시간
* -> 1,2를 통해 방문한 노드 중 이미 더 긴 것이 있으면 drop 가능.
* -> 위상 정렬.
* 1분도 안 쉬고 달린 도로 check
-> 해당 node에 마지막 도착한 시간, 마지막에 온 도로 개수 기록
현재 node의 도로 개수 = sum(이전 node에 적힌 개수 * 1)
현재 node의 last time = max(이전 node의 last time + 이전 node로부터의 걸린 시간)
-> 도로가 중복되는것은 count X
* 
*/
#include <iostream>
#include <vector>
using namespace std;
int n, m;
struct node{
	int n, w;
	int visited;
};
int connected[10001];
int last_time[10001];
vector <struct node> v[10001];
int S, D;
int ans = 0;
void topology(int n) {

	for (auto r : v[n]) {
		int nextn = r.n, cost = r.w;
		connected[nextn]--;
		if (last_time[nextn] < last_time[n] + cost) {
			last_time[nextn] = last_time[n] + cost;
		}

		if (connected[nextn] == 0) {
			topology(nextn);
		}
	}
}
int dfs(int n, int w) {
	if (n == D)return 1;
	int ret = 0;
	for (int i = 0; i < v[n].size();i++) {
		struct node* r = &v[n][i];
		if (w + r->w != last_time[r->n])continue;
		if (r->visited != 0){
			if (r->visited == 1)ret = 1;
			continue;
		}
		if (dfs(r->n, w + r->w) == 1) {
			r->visited = 1;
			ans++;
			ret = 1;
		}
		else r->visited = 2;
	}
	return ret;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	int a, b, c;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		connected[b]++;
	}
	cin >> S >> D;
	topology(S);
	dfs(S,0);
	cout << last_time[D] << '\n' << ans;
	return 0;
}
