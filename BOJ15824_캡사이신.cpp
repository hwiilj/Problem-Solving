/*
	brute force : O(2^n)
	Two pointer -> 정렬 후 양끝을 정하면 그 사이는 넣든 말든 상관없음. 
	모든 경우의 수 더하면 됨. 그래도 O(n^2)
	O(nlogn)으로 가능? 단순히 절반으로 분할하는것은 불가능.
	어떤 n이 있으면 n이 최대일 때 더해지고 n이 최소일 때 빼진다. 이를 이용

	$ ans가 음수가 되면 mod 연산이 깨지므로 양수로 만들어줘야 한다.
*/
#include <iostream>
using namespace std;
#define ull long long
#define MOD_VAL 1000000007
ull sqr2[300001];
ull arr[300000];
ull arr2[300000];
int counting[1 << 8];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N;
	ull ans = 0;

	sqr2[0] = 1;
	for (int i = 1; i <= 300000; i++) {
		sqr2[i] = sqr2[i - 1] * 2 % MOD_VAL;
	}

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < 32; i += 8) {
		for (int j = 0; j < (1 << 8); j++) {
			counting[j] = 0;
		}
		for (int j = 0; j < N;j++) {
			counting[(arr[j] >> i)& ((1 << 8) - 1)]++;
		}
		for (int j = 1; j < (1 << 8); j++)
			counting[j] += counting[j - 1];
		for (int j = N-1; j >= 0; j--) {
			arr2[--counting[(arr[j] >> i)& ((1 << 8) - 1)]] = arr[j];
		}
		for (int j = 0; j < N; j++)
			arr[j] = arr2[j];
	}
	for (int i = 0; i < N; i++) {
		ans -= (sqr2[(N - 1 - i)] * (arr[i]%MOD_VAL))%MOD_VAL;
		ans += (sqr2[i] * (arr[i] % MOD_VAL)) % MOD_VAL;
		ans = (ans% MOD_VAL + MOD_VAL)%MOD_VAL;
	}
	cout << ans;
	return 0;
}
