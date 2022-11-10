/*
* Union Find + LCA ? binary tree에 벗어나므로 불가능.
* 무게 차이 절대값 1M이하. -> seg tree?
* offline query. 들어온 무게비교를 쭉 정렬하여 가장 왼쪽을 segtree상 1번에 둔다.
* -> 최종 위치를 미리 알더라도 분리된 것들을 관리 불가능.
* -> find 시에 root를 업데이트와 동시에 diff도 update한다면?
*/
#include <iostream>
int diff[100001];
int root[100001];
using namespace std; 
int N;
int find(int n) {
	if (root[n] == 0) return n;
	else {
		int r =	find(root[n]);
		diff[n] += diff[root[n]];
		root[n] = r;
		return r;
	}
}
void merge(int a, int b, int v) {
	int pb = b;
	b = find(b);
	int pa = a;
	a = find(a);
	if (a == b) return;

	v -= diff[pb];
	v += diff[pa];
	root[b] = a;
	diff[b] = v;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int M;
	char q;
	int a, b, c;
	while (1) {
		cin >> N >> M;
		if (N == 0 && M == 0) break;
		for (int i = 1; i <= N; i++)
			root[i] = 0, diff[i] = 0;
		for (int i = 0; i < M; i++) {
			cin >> q;
			if (q == '!') {
				cin >> a >> b >> c;
				merge(a, b, c);				
			}
			else {
				cin >> a >> b;
				if (find(a) != find(b)) cout << "UNKNOWN\n";
				else
					cout << diff[b] - diff[a] << '\n';
			}
		}
	}
	return 0;
}
