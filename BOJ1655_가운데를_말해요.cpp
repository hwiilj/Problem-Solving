/*
* -10000 ~ 10000이므로
* segment tree 구성 후(기준점 보다 작은 것의 개수)
* binary search : O((log N)^2)
*/
#include <iostream>
using namespace std;
int arr[20002];
int N;
struct fenwick {
	int cnt[20002];
	void insert(int n) {
		n += 10001;
		while (n <= 20001) {
			cnt[n] ++;
			n += n & -n;
		}
	}
	int query(int n) {
		int ret = 0;
		n += 10001;
		while (n >= 1) {
			ret += cnt[n];
			n -= n & -n;
		}
		return ret;
	}
} tree;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int a;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> a;
		tree.insert(a);
		int r=-10000;
		int s = -10000, e = 10000;
		while (s <= e) {
			int m = (s + e) / 2;
			int q = tree.query(m);
			if (q < (i + 1) / 2) {
				s = m + 1;
				r = m + 1;
			}
			else {
				e = m - 1;
			}
		}
		cout << r << "\n";
	}


	return 0;
}
