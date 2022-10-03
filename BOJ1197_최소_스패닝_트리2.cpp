#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int V, E;
struct node {
	int s, d, w;
	bool operator <(struct node b) const {
		return w > b.w;
	}
};
bool comp(struct node a, struct node b) {
	return a.w < b.w;
}
vector<struct node> v;
int parent[10001];
int find(int n) {
	if (parent[n] == n)return n;
	else return parent[n] = find(parent[n]);
}
void merge(int s, int e) {
	int ps = find(s), pe = find(e);
	if (ps == pe);
	else {
		parent[pe] = ps;
	}
}
int main() {
	int s, d, w, cnt = 0, ans = 0;
	struct node r;
	cin >> V >> E;

	for (int i = 0; i < E; i++) {
		cin >> s >> d >> w;
		v.push_back({ s,d,w });
	}
	for (int i = 1; i <= V; i++)
		parent[i] = i;
	sort(v.begin(), v.end(), comp);
	for (int i = 0; i < v.size(); i++) {
		r = v[i];
		if (find(r.s) != find(r.d)) {
			merge(r.s, r.d);
			ans += r.w;
		}
	}
	cout << ans;
	return 0;
}
