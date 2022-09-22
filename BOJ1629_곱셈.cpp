/*
  D&C로 풀면 간단하지만, 
  이상하게 모듈러 산술에 홀려서
  헤맸던 문제  
*/
#include <cstdio>
int g(int A, int B, int C) {
	if (B == 1) return A % C;
	unsigned long long r = g(A, B / 2, C);
	unsigned long long ret;
	if (B % 2 == 0) ret = (r * r) % C;
	else ret = (r * r) % C * A % C;
	return (int)ret;
}
int main() {
	int A, B, C;
	scanf("%d %d %d", &A, &B, &C);
	printf("%d", g(A, B, C));
	return 0;
}

/* 모듈러 산술의 흔적
#include <cstdio>
#include <map>
using namespace std;
map<int, int> m;
int arr[1000000];
int main() {
	unsigned long long A, B, C;
	int ans = 1;
	int s, r;

	scanf("%lld %lld %lld", &A, &B, &C);
	s = 0;
	for (int i = 0; i < B; i++) {
		ans = (ans * (A % C))%C;
		arr[i] = ans;
		if (m.find(ans) == m.end()) {
			m[ans] = i;
		}
		else {
			r = i - m[ans];
			s = m[ans];
			break;
		}
	}
	printf("%lld", arr[s+(B-s)%r]);
	return 0;
}
*/
