#include <cstdio>
#include <algorithm>
using namespace std;
#define mix(a, b) (a+b>0)?(a+b):((a+b)*(-1))
int arr[100000];
int main() {
	int N, l, r, ans[2], max = 2000000000;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	sort(arr, arr + N);
	l = 0, r = N - 1;
	while (l < r) {
		int ret =arr[l] + arr[r];
		
		if (abs(ret) < max) {
			max = abs(ret);
			ans[0] = l;
			ans[1] = r;
		}
		if (ret<0) {
			l++;
		}
		else
			r--;
	}
	printf("%d %d", arr[ans[0]], arr[ans[1]]);
	return 0;
}
