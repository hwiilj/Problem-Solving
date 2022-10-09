#include <iostream>
using namespace std;
int arr[1000000];
int n;
int lis[1000000];
int ptr = -1;
int findw(int v) {
	int s = 0, e = ptr, m;
	int ret = -1;
	while (s <= e) {
		m = (s + e) / 2;
		if (lis[m] >= v) {
			ret = m;
			e = m - 1;
		}
		else {
			s = m + 1;
		}
	}
	return ret;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++) {
		int w = findw(arr[i]);
		if (w == -1) {
			lis[++ptr] = arr[i];
		}
		else {
			lis[w] = arr[i];
		}
	}
	cout << ptr+1;
	return 0;
}
