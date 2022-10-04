/*
  Topology Sort
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N, M;
int edge[32001];
vector <int>v[32001];
queue <int> q;
int main() {
	int s, e;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> s >> e;
		v[s].push_back(e);
		edge[e]++;
	}
	for (int i = 1; i <= N; i++) {
		if (edge[i] == 0)q.push(i);
	}
	while (!q.empty()) {
		int r = q.front();
		q.pop();
		cout << r << " ";
		for (auto n : v[r]) {
			if (--edge[n] == 0) q.push(n);
		}
	}
	return 0;
}
