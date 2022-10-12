/*
	부모가 1이면, 자식은 0,1 가능
	부모가 0이면, 자식은 반드시 1
	dp[parent][1] = sum(min(dp[child][1], dp[child][0]));
	dp[parent][0] = sum(dp[child][1]);

	주의) 주어진 u, v는 연결되어있다고만 되어있지 부모, 자식 관계라고 나와있지 않다.
*/
#include <iostream>
#include <vector>
using namespace std;
int N;
vector<int> tree[1000001];
int dp[1000001][2];
int visited[1000001];
void dfs(int n) {
	visited[n] = 1;
	if (tree[n].size() == 0) {
		dp[n][0] = 0;
		dp[n][1] = 1;
		return;
	}
	for (auto m : tree[n]) {
		if (visited[m]) continue;
		dfs(m);
		dp[n][1] += min(dp[m][0], dp[m][1]);
		dp[n][0] += dp[m][1];
	}
	dp[n][1]++;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int a, b, ans= 0;
	cin >> N;

	for (int i = 0; i < N - 1; i++) {
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	for (int i = 1; i <= N; i++) {
		if (visited[i] == 0) {
			dfs(i);
			ans += min(dp[i][1], dp[i][0]);
			break;
		}
	}
	cout << ans;
	
	return 0;
}
