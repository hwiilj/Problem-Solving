/*
	Naive한 접근, 선분 전체에 사람의 이동경로를 전부 표시한다.
	그 뒤 선분 전체를 O(n)으로 탐색한다.
	선분 20M, 사람 100K, 전체 표시는 불가능. 탐색은 가능.

	더 나은 풀이, 선분이 시작되는 곳에 +1, 끝나는 다음 곳에 -1
	그 뒤 누적 합을 구한다. 
	-> X. 이러면 선분 구분이 불가능.

	출발점 기준 정렬 하여 s0, s1, ..이고, 철로 길이가 d라고하면
	s0 + d안에 포함되는 것, 1. s1, s2 중 s0 + d이하여야 하고,
	2. e0,e1,...또한 s0 + d이하여야 한다.
	정렬하여 1번 조건에 맞는 것만 heap에 넣는다.
	그 heap은 2번 조건에서는 e가 작은 것을 우선순위로 한다.
	e가 s0+d보다 작으면 버린다.

	-> 시간 초과, 순회 때마다 전부 heap에 넣는 것이 불필요.
	도착점 기준으로 정렬하면 순회 때마다 해당 사람만 push하면 된다.

*/
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int n;
int d;
pair<int, int> arr[100000];
int deleted[100000];

bool cmp(pair<int, int>a, pair<int, int>b) {
	return a.second < b.second;
};

priority_queue <pair<int, int>, vector<pair<int, int>>, greater<>> pq;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int a, b;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		if (a > b)
			arr[i].first = b, arr[i].second = a;
		else
			arr[i].first = a, arr[i].second = b;
	}
	cin >> d;
	sort(arr, arr + n, cmp);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		pq.push(arr[i]);
		while (!pq.empty() && pq.top().first < arr[i].second-d)
			pq.pop();
		if (ans < pq.size())
			ans = pq.size();
	}

	cout << ans;
	return 0;
}
