/*
	1. 가장 가중치가 낮은 간선을 택한다.
	2. 그 간선을 택했을 떄 cycle이 이루어지는지 체크한다.

	1. 현재 출발한 그래프에서 출발하여 연결되지 않은 정점으로
	가는 가장 가중치가 낮은 간선을 택한다.
*/
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int V, E;
struct node {
	int d, w;
	bool operator <(struct node b) const {
		return w > b.w;
	}
};

priority_queue <struct node, vector<struct node>, less<struct node> > pq;
vector<struct node> q[10001];
int visited[10001];
struct node line[200001];
int main() {
	int s, d, w,cnt=0, ans=0;
	struct node r;
	cin >> V >> E;

	for (int i = 0; i < E; i++) {
		cin >>  s >> d >> w;
		q[s].push_back({ d,w });
		q[d].push_back({ s,w });
	}
	pq.push({ 1,0 });
	while (cnt < V) {
		r = pq.top();
		pq.pop();
		if (visited[r.d])continue;
		visited[r.d] = 1;
		ans += r.w; 
		cnt++;
		for (int i = 0; i < q[r.d].size(); i++) {
			if (visited[q[r.d][i].d])continue;
			pq.push(q[r.d][i]);
		}
	}
	cout << ans;
	return 0;
}
