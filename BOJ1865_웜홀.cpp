/*
  Bellman-Ford Alg.
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct node {
	int S, E, T;
};
vector<struct node>v;
long long arr[501];
void solve() {
	int N, M, W, S, E, T;
	cin >> N >> M >> W;
	int ans = 0;

	v.clear();
	for (int i = 1; i <= N; i++) {
		arr[i] = (long long)1 << 60;
	}
	for (int i = 0; i < M; i++) {
		cin >> S >> E >> T;
		v.push_back({ S,E,T });
		v.push_back({ E,S,T });
	}
	for (int i = 0; i < W; i++) {
		cin >> S >> E >> T;
		v.push_back({ S,E,-T });
	}
	arr[1] = 0;
	for (int i = 0; i < N-1; i++) {
		for (int j = 0; j < v.size(); j++) {
			if (arr[v[j].E] > arr[v[j].S] + v[j].T)
				arr[v[j].E] = arr[v[j].S] + v[j].T;
		}
	}
	for (int j = 0; j < v.size(); j++) {
		if (arr[v[j].E] > arr[v[j].S] + v[j].T)
			ans = 1;
	}
	if (ans)
		cout << "YES\n";
	else
		cout << "NO\n";
}
int main() {
	int TC;
	cin >> TC;
	while (TC--) solve();
	return 0;
}
