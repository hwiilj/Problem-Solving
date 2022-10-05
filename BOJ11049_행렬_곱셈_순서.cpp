/*
	완탐 : 1~499 순열
	DP ? : 500
	dp[i] = max(dp[i-1]+ S(i-1)*A(i) , dp[i-2] + S(i-2)*(A(i-1)*A(i)))
	-> 뿐만 아니라 모든 S(i-1)*A(i), S(i-2)*S(2~1) ~ S(1)*S(2~i) 까지를 전부 고려해야한다.
*/
#include <iostream>
#include <algorithm>
#define MAX ((1<<31) -1)
struct node {
	unsigned int r, c;
};
struct node arr[501];
unsigned int dp[501][501];
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i].r >> arr[i].c;
	}
	for (int i = 2; i <= N; i++) {
		for (int j = 1; j <= N - i +1; j++) {
			unsigned int m = MAX;
			for (int k = 0; k < i-1; k++) {
				m = min(dp[j][j+k] + dp[j+k+1][j+i-1] + arr[j].r*arr[j+k].c*arr[j+i-1].c, m);
			}
			dp[j][j + i - 1] = m;
		}
	}
	cout << dp[1][N];
	return 0;
}
