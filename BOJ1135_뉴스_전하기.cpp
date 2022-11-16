/*
* 1. 자식노드를 counting 한다. 
* 2. 자식들 중 자식노드가 많은 자식에게 먼저 전화를 한다?
* -> X. 자식과 손자 중 중요도 비교 불가.
* 결국 다 도는 수 밖에 없음.
* DFS 돌고 나서 가장 오래 걸린 자식을 기준으로 본인의 return 값을 결정.
* 2,3번째가 하나씩 늦게 출발하기 때문에 만약 max값이 다수일 경우 max값을 가진 개수를 더해줄 필요는 있다.
* -> X 5 4 4 인 경우 5보다 4+2가 더 높으므로 불가능.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
int arr[50];
vector<int> child[50];

int dfs(int n) {
	if (child[n].size() == 0) return 1;
	int max = -1;
	vector<int> child_sum;
	for (auto a : child[n]) {
		int r = dfs(a);
		child_sum.push_back(r);
	}
	sort(child_sum.begin(), child_sum.end(), greater<int>());
	for (int i = 0; i < child_sum.size(); i++) {
		if (max < child_sum[i] + i) {
			max = child_sum[i] + i;
		}
	}
	return max + 1;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	int c;
	for (int i = 0; i < N; i++) {
		cin >> c;
		if (c == -1)continue;
		child[c].push_back(i);
	}
	cout << dfs(0) - 1; // root 제외


	return 0;
}
