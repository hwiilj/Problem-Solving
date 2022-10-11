/*
	LIS - O(NlogN)
	교체를 해버리면 실제 수열을 복원할 수 없다.
	방법? 역으로 돌아가며 찾을 수 있나?
	N 배열에 각각 들어간 위치 기록한 뒤 역순회하여 복원
*/
#include <iostream>
using namespace std;
int N;
int arr[1000000];
int mem[1000000];
int buf[1000000];
int check[100000];
int len = 0;
int findindex(int s, int e, int v) {
	int m, r = -1;
	while (s <= e) {
		m = (s + e) / 2;
		if (buf[m] < v) {
			s = m + 1;
		}
		else {
			e = m - 1;
			r = m;
		}
	}
	return r;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		int r = findindex(0, len - 1, arr[i]);
		if (r == -1) {
			buf[len] = arr[i];
			mem[i] = len++;
		}
		else {
			buf[r] = arr[i];
			mem[i] = r;
		}
	}
	int tmp = len-1;
	for (int i = N - 1; i >= 0; i--) {
		if (mem[i] == tmp) {
			buf[mem[i]] = arr[i];

			if (tmp == 0) break;
			tmp--;

		}
	}
	cout << len << '\n';
	for (int i = 0; i < len; i++)
		cout << buf[i] << " ";
	return 0;
}
