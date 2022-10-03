/*
  최소 비용을 갖는 2개의 그룹의 그래프를 만드는 것은
  MST 크루스칼 알고리즘 중 N-2개를 연결하면 된다.
*/
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int N, M;
int parent[100001];
struct node {
	int s;
	int d;
	int w;
	bool operator < (struct node b) const {
		return w < b.w;
	}
};
bool cmp(struct node a, struct node b) {
	return a.w < b.w;
}
int find(int n ) {
	if (parent[n] == n) return n;
	else return parent[n] = find(parent[n]);
}
void merge(int a, int b) {
	a = parent[a];
	b = parent[b];
	if (a != b)parent[b] = a;
}
vector<struct node> pq;
int main() {
	int a, b, c, cnt=0, ans=0;
	int r1, r2;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		pq.push_back({ a,b,c });
	}
	sort(pq.begin(), pq.end(), cmp);
	for (int i = 1; i <= N; i++)
		parent[i] = i;

	for (int i = 0; i < pq.size(); i++) {
		r1 = pq[i].s, r2 = pq[i].d;
		if (find(r1) != find(r2)) {
			merge(r1, r2);
			ans += pq[i].w;
			cnt++;
			if (cnt == N - 2)break;
		}
	}

	cout << ans;
	
	return 0;
}
