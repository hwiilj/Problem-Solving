/*
  root, leaf 판단이 어렵기 때문에
  임의의 점에서 가장 먼 점을 찾아,
  해당 점에서 가장 먼 점까지의 거리가 지름이다.
*/
#include <iostream>
#include <vector>
using namespace std;
struct node {
	int dst;
	unsigned long long dist;
};
vector <struct node> v[100001];
unsigned long long ans = 0;
int ans_point;
int visited[100001];
void dfs(int c, unsigned long long d) {
	visited[c] = 1;
	if (d > ans) {
		ans = d;
		ans_point = c;
	}

	for (int i = 0; i < v[c].size(); i++) {
		if (!visited[v[c][i].dst])
			dfs(v[c][i].dst, d + v[c][i].dist);
	}
}
int main() {
	int n, a, b;
	unsigned long long c;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		while (1) {
			cin >> b;
			if (b == -1)break;
			cin >> c;
			v[a].push_back({ b,c });
		}
	}
	dfs(1,0); 
	for (int i = 1; i <= n; i++)
		visited[i] = 0;
	dfs(ans_point,0);
	cout << ans << '\n';

	return 0;
}
