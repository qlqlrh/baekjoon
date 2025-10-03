#include <bits/stdc++.h>

using namespace std;

int main() {
	int N;
	cin >> N;

	queue<int> q;
	for (int i = 1; i <= N; i++) {
		string command;
		cin >> command;

		if (command == "push") {
			int num;
			cin >> num;
			q.push(num);
		}
		else if (command == "pop") {
			int front;
			if (q.empty()) front = -1;
			else {
				front = q.front();
				q.pop();
			}
			cout << front << '\n';
		}
		else if (command == "size") {
			cout << q.size() << '\n';
		}
		else if (command == "empty") {
			cout << (q.empty() ? 1 : 0) << '\n';
		}
		else if (command == "front") {
			cout << (q.empty() ? -1 : q.front()) << '\n';
		}
		else if (command == "back") {
			cout << (q.empty() ? -1 : q.back()) << '\n';
		}
	}
}