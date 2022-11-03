/*
	fenwick
	내 위치 * (좌측에 있는 개수)- 좌측에 있는 위치들의 합 
	우측은 반대로
	1. 좌표가 0인것 유의
	2. 같은 곳에 심어질 경우 반대쪽 sum에 더해지는 것 유의
*/
#include <iostream>
using namespace std;
#define ll long long
int N;
int arr[200001];
ll sum_tree[200001];
ll count_tree[200001];
ll ans;
void update(int n) {
	int t = n+1;
	while (t <= 200000) {
		sum_tree[t] += n;
		count_tree[t]++;
		t += t & -t;
	}	
}
ll sum_query(int s) {
	ll rv = 0;
	s++;
	while (s > 0) {
		rv += sum_tree[s];
		s -= s & -s;
	}
	return rv;
}
ll cnt_query(int s) {
	ll rv = 0;
	s++;
	while (s > 0) {
		rv += count_tree[s];
		s -= s & -s;
	}
	return rv;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	ans = 1;
	ll total_sum=0;
	cin >> arr[1], update(arr[1]);
	total_sum += arr[1];
	
	for (int i = 2; i <= N; i++) {
		ll r;
		cin >> arr[i];
		ll cnt = cnt_query(arr[i] - 1), sumv = sum_query(arr[i]-1);
		r = (cnt - ((ll)i-1-cnt)) * arr[i]
			- (sumv - (total_sum - sumv));
		update(arr[i]);
		total_sum += arr[i];
		ans = (ans * (r % 1000000007)) % 1000000007;
	}

	cout << ans;
	return 0;
}
