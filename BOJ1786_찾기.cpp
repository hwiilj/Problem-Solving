#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define MAX_LEN 1000002
vector<int> kmp;
string s, p;
int ans = 0, ans_stack[MAX_LEN];
void make_kmp(string p) {
	int l = 0, j = 0, plen = p.length();
	kmp.resize(plen, 0);
	kmp[j++] = l;
	for(int i=1;i< plen;i++){
		while (l != 0 && p[l] != p[i]) {
			l = kmp[l - 1];
		}
		if(p[l] == p[i])
			kmp[i] = ++l;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	getline(cin, s);
	getline(cin, p);

	make_kmp(p);
	int l = 0, plen = p.length(), slen = s.length();
	for (int i = 0; i < slen; i++) {
		while (l != 0 && s[i] != p[l]) {
			l = kmp[l - 1];
		}
		if (s[i] == p[l]) {
			if (l == plen - 1) {
				ans_stack[ans++] = i - plen + 1;
				l = kmp[l];
			}
			else {
				l++;
			}
		}
	}
	cout << ans << '\n';
	for (int i = 0; i < ans; i++) {
		cout << ans_stack[i] + 1 << ' ';
	}
	return 0;
}
