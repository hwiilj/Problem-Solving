/*
  greedy는 greedy인걸 알고 풀어도
  컨디션 나쁘면 solution이 안 떠오른다.
*/
#include <cstdio>
#include <stack>
#include <algorithm>
using namespace std;
struct meet{
	int s;
	int e;
	bool operator<(meet b) {
		if (e == b.e)return s < b.s;
		return e < b.e;
	}
};
meet c[100000];
int ans = 0;
int main() {
	int n, count, cur, ans=0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d %d", &c[i].s, &c[i].e);
	sort(c, c+n );
	cur = -1;
	for (register int i = 0; i < n; i++) {
		if (c[i].e >= cur && c[i].s >= cur) {
			ans++;
			cur = c[i].e;
		}

	}
	printf("%d", ans);
	return 0;
}
