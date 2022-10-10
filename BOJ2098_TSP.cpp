/*
	dp[current, visited] = dp[next, visited+next] + w[current->next]
	#1 visited에 첫 current를 포함시키지 않고, leaf node에서 visited current를 포함 시키고 비용은 0으로 함.(#2보다 더 느림. 가지가 더 늘어남)
	#2 visited에 첫 current를 포함시키고, leaf node에서 all visited일 때, start point로의 비용을 더해줌.
	
	- dp[c][bitmask]를 MAX로 설정해놓지않고 loop에 들어가면, 아무 경로가 없음에도 0을 반환하여 상위 노드를 min 값으로 차지하게 된다.
  - 최소 경로가 존재한다면 searching은 아무 곳에서나 출발해도 상관없다.
*/
#include <iostream>
using namespace std;

int N;
int arr[16][16];
int dp[16][65536];

int tsp(int s, int c, int bitmask) {
	if (bitmask == (1 << N) - 1) {
		return 0;
	}
	if (dp[c][bitmask])return dp[c][bitmask];
	dp[c][bitmask] = 20000000;
	for (int i = 0; i < N; i++) {
		if (arr[c][i] == 0)continue;
		if (bitmask & (1 << i))continue;
		int nmask = bitmask | (1 << i);
		if (i!=s && nmask == (1 << N) - 1) continue;
		int ret = tsp(s, i, nmask) + arr[c][i];
		//if(dp[c][bitmask]==0 || dp[c][bitmask] > ret)
			if(dp[c][bitmask]>ret)
				dp[c][bitmask] = ret;
	}
	return dp[c][bitmask];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	int ans = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];
//	for (int i = 0; i < N; i++)
		tsp(0, 0, 0);
	for (int i = 0; i < N; i++) {
		if (ans == 0 || dp[i][(1 << N) - 1] < ans)
			ans = dp[i][(1 << N) - 1];
	}
	cout << dp[0][0];
	
}
