/*
  DFS with Bitmask
*/
#include <iostream>
using namespace std;

char arr[21][21];
int dir[4][2] = { {1,0},{0,1},{0,-1}, {-1,0} };
int R, C, ans=0;
int bitmask(int val) {
	int ret = 0;
	while (val) {
		val &= val - 1;
		ret++;
	}
	return ret;
}
void proceed(int r, int c, int track) {
	int d = bitmask(track);
	if (d > ans) ans = d;
	for (int i = 0; i < 4; i++) {
		int nr = r + dir[i][0], nc = c + dir[i][1];
		if (nr < 0 || nc < 0 || nr >= R || nc >= C || (track & (1<<(arr[nr][nc]-'A'))))continue;
		proceed(nr, nc, track | (1<< (arr[nr][nc]-'A')));
	}
}

int main() {
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> arr[i][j];
		}
	}
	proceed(0, 0, 1 << (arr[0][0] - 'A'));
	cout << ans;
	return 0;
}
