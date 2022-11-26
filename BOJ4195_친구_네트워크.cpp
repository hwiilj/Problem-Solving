/*
	Union Find + Hash
*/
#include <iostream>
using namespace std;

struct joint {
	int root;
	int cnt;
}joint_array[200001];
int person_cnt;
#define HASH_SIZE 400003
struct hash {
	char s[21];
	int pushed;
	int index;
}hash_array[HASH_SIZE];

int find(int n) {
	if (joint_array[n].root == n) return n;
	else {
		return joint_array[n].root = find(joint_array[n].root);
	}
}
int merge(int a, int b) {
	a = find(a), b = find(b);
	if (a == b)return joint_array[a].cnt;
	joint_array[b].root = a;
	return joint_array[a].cnt += joint_array[b].cnt;
}

int hash_func(char s[21]) {
	int r = 0;
	for (int i = 0; s[i]; i++) {
		r = r * 21 + s[i];
		r %= HASH_SIZE;
	}
	return r;
}
int push(char s[21]) {
	int h = hash_func(s);
	while (1) {
		int flag = 0;
		if (hash_array[h].pushed) {
			for (int i = 0; s[i]; i++) {
				if (hash_array[h].s[i] != s[i]) {
					flag = 1;
					break;
				}
			}
		}
		if (flag == 1) {
			h = (h + 1) % HASH_SIZE;
		}
		else {
			if (!hash_array[h].pushed) {
				for (int i = 0; s[i]; i++) {
					hash_array[h].s[i] = s[i];
				}
				hash_array[h].pushed = 1;
				hash_array[h].index = person_cnt++;
			}
			return hash_array[h].index;
		}
	}
}

void solve() {
	int F;
	cin >> F;
	char a[21], b[21];
	person_cnt = 0;
	for (int i = 0; i < 200001; i++) {
		joint_array[i].cnt = 1;
		joint_array[i].root = i;
	}
	for (int i = 0; i < HASH_SIZE; i++) {
		hash_array[i].pushed = 0;
	}
	for (int i = 0; i < F; i++) {
		cin >> a >> b;
		// 1. push and get index
		int hash_a = push(a);
		int hash_b = push(b);
		
		// 2. find and union 
		cout << merge(hash_a, hash_b) << "\n";
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
	return 0;
}
