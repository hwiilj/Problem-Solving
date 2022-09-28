/*
  문자열은 그대로 출력
  )가 나오면 (까지 pop
  +,-보다 *,/가 우선순위가 높으므로 stack에 존재하면 전부 pop
  마지막 stack에 남아있는 것을 전부 pop
*/
#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <string>
using namespace std;
stack <char> st;

int main() {
	string str;
	cin >> str;
	for (int i = 0; i < str.length(); i++) {
		switch(str[i]) {
		case '(':
			st.push('(');
			break;
		case ')':
			while (!st.empty()) {
				char c = st.top();
				st.pop();
				if (c == '(')break;
				cout << c;
			}
			break;
		case '+':
		case '-':
			while (!st.empty()) {
				char c = st.top();
				if (c == '(')
					break;
				cout << c;
				st.pop();	
			}
			st.push(str[i]);
			break;
		case '*':
		case '/':
			while (!st.empty()) {
				char c = st.top();
				if (c == '*' || c == '/') {
					cout << c;
					st.pop();
				}
				else break;
			}
			st.push(str[i]);
			break;
		default:
			cout << str[i];
			break;
		}
	}
	while (!st.empty()) {
		cout << st.top();
		st.pop();
	}

	return 0;
}
