#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	while (true) {
		string s;
		getline(cin, s);
		if (s == ".") break;

		stack<char> st;
		bool flag = true;
		for (char c : s) {
			if (c == '(' or c == '[') st.push(c);
			else if (c == ')') {
				if (!st.empty() && st.top() == '(') st.pop();
				else {
					flag = false;
					break;
				}
			}
			else if (c == ']') {
				if (!st.empty() && st.top() == '[') st.pop();
				else {
					flag = false;
					break;
				}
			}
		}
		if (flag && st.empty()) cout << "yes\n";
		else      cout << "no\n";
	}
}