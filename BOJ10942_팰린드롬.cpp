/*
	dp[i][j] = dp[i+1][j-1] && arr[i]==arr[j]
*/
#include <iostream>
using namespace std;
int N;
int arr[2001];
int dp[2001][2001];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int M, S, E;
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> arr[i];
	for (int l = 1; l <= N; l++) {
		for (int i = 1; i <= N && i+l-1<=N; i++) {
			int j = i + l-1;
			if(i+1<=j-1)
				dp[i][j] = dp[i + 1][j - 1] && (arr[i] == arr[j]);
			else {
				dp[i][j] = (arr[i] == arr[j]);
			}
		}
	}
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> S >> E;
		cout << dp[S][E] << '\n';
	}
	return 0;
}
