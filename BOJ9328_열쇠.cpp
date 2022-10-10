/*
  DFS
	알파벳 vector는 각 문의 좌표를 모두 가지고 있다.
	DFS도 중 키를 만나면 해당 문부터 전부 DFS시도한다.
	-> X. 방문 못하는 문있으면 불가능. 
	입력할 때 문의 좌표를 가지고 있는 것이 아닌 열쇠가 없어서 
	못들어갔던 문의 좌표만 vector에 집어넣는다.
	
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int h, w;
char arr[102][102];
int visited[102][102];
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };
int ans = 0;
vector<pair<int, int>> v[26];
int key[26];
string s;
void dfs(int y, int x) {
	int ny, nx;
	if (arr[y][x] == '$')ans++;
	else if (arr[y][x] >= 'a' && arr[y][x] <= 'z') {
		key[arr[y][x] - 'a'] = 1;
		for (auto n : v[arr[y][x] - 'a']) {
			if (visited[n.first][n.second]) continue;
			visited[n.first][n.second] = 1;
			dfs(n.first, n.second);
		}
	}

	for (int i = 0; i < 4; i++) {
		ny = y + dy[i], nx = x + dx[i];
		if (visited[ny][nx])continue;
		if (ny < 0 || nx < 0 || ny > h+1 || nx > w+1) continue;
		if (arr[ny][nx] == '*')continue;
		if (arr[ny][nx] >= 'A' && arr[ny][nx] <= 'Z' && key[arr[ny][nx]-'A']==0) {
			v[arr[ny][nx] - 'A'].push_back({ ny,nx });
			continue;
		}
		visited[ny][nx] = 1;
		dfs(ny, nx);
	}
}
void solve() {
	ans = 0;
	cin >> h >> w;
	for (int i = 0; i < 26; i++) {
		v[i].clear();
		key[i] = 0;
	}
	for (int i = 0; i <= h + 1; i++) {
		for (int j = 0; j <= w + 1; j++) {
			arr[i][j] = 0;
			visited[i][j] = 0;
		}
	}
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			cin >> arr[i][j];
		}
	}
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		key[s[i] - 'a'] = 1;
	}
	
	dfs(0, 0);
	cout << ans << '\n';
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--)solve();
	return 0;
}
