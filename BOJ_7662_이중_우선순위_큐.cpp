/*
  pq 2개와 삭제를 lazy하게 하여 해결
*/
#include <iostream>
#include <queue>
#include <map>

using namespace std;
int main() {
	int test_case;
	cin >> test_case;
	for (int t = 1; t <= test_case; t++) {
		int N;
		char c;
		long long d;
		priority_queue<long long, vector<long long >, greater<long long >> min_heap;
		priority_queue<long long, vector<long long >, less<long long>> max_heap;
		map<long long, long long >m;
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> c >> d;
			if (c == 'I') {
				min_heap.push(d);
				max_heap.push(d);
				if (m.find(d) != m.end())
					m[d]++;
				else
					m[d] = 1;
			}
			if (c == 'D') {
				if (d == 1) {
					while (!max_heap.empty()) {
						long long r = max_heap.top();
						max_heap.pop();
						if (m[r] > 0) {
							m[r]--;
							break;
						}				
					}
				}
				else {
					while (!min_heap.empty()) {
						long long  r = min_heap.top();
						min_heap.pop();
						if (m[r] > 0) {
							m[r]--;
							break;
						}
					}
				}
			}
		}
		while (!max_heap.empty()) {
			long long  r = max_heap.top();
			if (m[r] > 0) {
				break;
			}
			max_heap.pop();
		}
		while (!min_heap.empty()) {
			long long  r = min_heap.top();
			if (m[r] > 0) {
				break;
			}
			min_heap.pop();
		}
		if (max_heap.empty())
			cout << "EMPTY" << endl;
		else {
			cout << max_heap.top() << " " << min_heap.top() << endl;
		}
	}
	return 0;
}
