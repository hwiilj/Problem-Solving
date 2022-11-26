/*
	Topology Sort + Priority Queue
*/
#include <iostream>
#include <vector>
using namespace std;
int N;
struct remain {
	int cnt=0;
	vector<int> v;
}r[32001];
struct priority_queue {
	int arr[32001];
	int sz = 0;
	void push(int v) {
		int c = ++sz;
		while (c > 1) {
			if (arr[c >> 1] > v) {
				arr[c] = arr[c >> 1];
			}
			else break;
			c >>= 1;
		}
		arr[c] = v;
	}
	int pop() {
		int r = arr[1], v = arr[sz--];
		int p=1, c=2;
		while (c<=sz) {
			if (c + 1 <= sz && arr[c] > arr[c + 1]) c++;
			if (v > arr[c]) {
				arr[p] = arr[c];
				p = c;
				c <<= 1;
			}
			else {
				break;
			}
			
		}
		arr[p] = v;
		return r;
	}
}ready;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int M, a, b;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		r[b].cnt++;
		r[a].v.push_back(b);
	}
	for (int i = 1; i <= N; i++) {
		if (!r[i].cnt)
			ready.push(i);
	}
	while (ready.sz) {
		int c = ready.pop();
		cout << c << "\n";
		for (int i = 0; i < r[c].v.size(); i++) {
			if (!--r[r[c].v[i]].cnt) {
				ready.push(r[c].v[i]);
			}			
		}		
	}
	

}
