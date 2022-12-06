#include <iostream>
using namespace std;
int N, Q;
int par[200001];
int root[200001];
int level[200001];
struct cmd {
	int cmd, arg1, arg2;
}cmd[400005];
int ans[400005], ans_cnt = -1;

int find(int n) {
	if (root[n] != n) return root[n] = find(root[n]);
	return root[n];
}
void merge(int a, int b) {
	a = find(a), b = find(b);
	if (a == b)return;
	if (level[a] > level[b])
		a ^= b ^= a ^= b;
	root[a] = b;
	if (level[a] == level[b])
		++level[b];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int a, b, c, d;

	cin >> N >> Q;
	root[1] = 1;
	for (int i = 2; i <= N; i++) {
		cin >> par[i];
		root[i] = i, level[i] = 1;
	}

	for (int i = 0; i < Q+N-1; i++) {
		cin >> a;
		if (a == 0) {
			cin >> b;
			cmd[i].cmd = 0, cmd[i].arg1 = b;
		}
		else if(a==1){
			cin >> c >> d;
			cmd[i].cmd = 1, cmd[i].arg1 = c, cmd[i].arg2 = d;
		}
	}

	for (int i = Q +N-2; i >= 0; i--) {
		if (cmd[i].cmd == 0) {
			merge(cmd[i].arg1, par[cmd[i].arg1]);
		}
		else if(cmd[i].cmd==1) {
			c = find(cmd[i].arg1), d = find(cmd[i].arg2);
			if (c == d) {
				ans[++ans_cnt] = 1;
			}
			else
				ans[++ans_cnt] = 0;
		}
	}
	for (int i = ans_cnt; i >= 0; i--) {
		if (ans[i])
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return 0;
}
