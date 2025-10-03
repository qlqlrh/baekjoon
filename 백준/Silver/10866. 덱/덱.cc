#include <bits/stdc++.h>

using namespace std;

int main() {
	int N;
	cin >> N;

	deque<int> deq;
	for (int i = 1; i <= N; i++) {
		string command;
		cin >> command;

		if (command == "push_front") {
			int num;
			cin >> num;
			deq.push_front(num);
		}
		else if (command == "push_back") {
			int num;
			cin >> num;
			deq.push_back(num);
		}
		else if (command == "pop_front") {
			int front;
			if (deq.empty()) front = -1;
			else {
				front = deq.front();
				deq.pop_front();
			}
			cout << front << '\n';
		}
		else if (command == "pop_back") {
			int back;
			if (deq.empty()) back = -1;
			else {
				back = deq.back();
				deq.pop_back();
			}
			cout << back << '\n';
		}
		else if (command == "size") {
			cout << deq.size() << '\n';
		}
		else if (command == "empty") {
			cout << (deq.empty() ? 1 : 0) << '\n';
		}
		else if (command == "front") {
			cout << (deq.empty() ? -1 : deq.front()) << '\n';
		}
		else if (command == "back") {
			cout << (deq.empty() ? -1 : deq.back()) << '\n';
		}
	}
}