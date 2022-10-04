/*
	N개 중 2개를 고른 것의 합을 구해 정렬한다.
	two pointer : array of N, array of two sum
	? two sum에서 찾았는데 중복되는 경우는? 불가능

	N loop 에서 two pointer 활용하면 O(N^2)로 가능.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
int arr[5000];
long long m = (long long)1 << 60;
int ans[3];
void search() {	
	for (int i = 0; i < N - 2; i++) {
		int s = i + 1, e = N - 1;
		long long r = (long long)arr[i] + arr[s] + arr[e];
		while (s < e) {

			if (abs(r) < m) {
				m = abs(r);
				ans[0] = arr[i];
				ans[1] = arr[s];
				ans[2] = arr[e];
			}
			if (r < 0) {
				r -= arr[s];
				r += arr[++s];
			}
			else {
				r -= arr[e];
				r += arr[--e];
			}
		}
	}
}
int main() {
	int r1, r2;
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	
	sort(arr, arr + N);
	search();
	cout << ans[0] << " " << ans[1] << " " << ans[2];
	return 0;
}
