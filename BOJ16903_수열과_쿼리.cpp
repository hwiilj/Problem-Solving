/*
Trie만 구현하면 되는 문제인데, segmentation fault 나와서 한참 디버깅했는데
알고보니 1. 처음에 0이 추가되어있는 걸 빼먹었고
2. node 만들어놓고 counting을 부모노드에다 해버려서 꼬이게 되었다.
*/
#include <iostream>
using namespace std;

struct Trie {
	struct Trie *v[2];
	int count = 0;
	
	Trie() {
		count = 0;
		v[0] = v[1] = NULL;
	}
	void insert(unsigned int x, int idx) {
		if (idx < 0) return;
		bool bit = (x >> idx) & 0x1;
		if (bit) {
			if (v[1] == NULL)
				v[1] = new Trie();
			v[1]->count++;
			v[1]->insert(x, idx - 1);
		}
		else {
			if (v[0] == NULL)
				v[0] = new Trie();
			v[0]->count++;
			v[0]->insert(x, idx - 1);
		}
	}
	void erase(unsigned int x, int idx) {
		if (idx < 0)return;
		bool bit = (x >> idx) & 0x1;
		if (bit) {
			v[1]->erase(x, idx - 1);
			v[1]->count--;
			if (v[1]->count<=0) {
				delete v[1];
				v[1] = NULL;
			}
		}
		else {
			v[0]->erase(x, idx - 1);
			v[0]->count--;
			if (v[0]->count<=0) {
				delete v[0];
				v[0] = NULL;
			}
		}
	}
	unsigned int find(unsigned int x, int idx) {
		if (idx < 0)return 0;
		bool bit = (x>>idx)&0x1;
		if (bit) {
			if (v[1]) {
				return v[1]->find(x, idx - 1) | (1 << idx);
			}
			else {
				return v[0]->find(x, idx - 1);
			}
		}
		else {
			if (v[0]) {
				return v[0]->find(x, idx - 1);
			}
			else {
				return v[1]->find(x, idx - 1) | (1 << idx);
			}
		}
	}
};
struct Trie root = Trie();
int cnt = 0;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int M;
	unsigned int o, x;
	cin >> M;
	root.insert(0, 31);
	for (int i = 0; i < M; i++) {
		cin >> o >> x;
		if (o == 1)
			root.insert(x, 30);
		else if (o == 2)
			root.erase(x, 30);
		else {
			unsigned int r = root.find(~x, 30);
			cout << (r^x) << '\n';
		}
	}
}
