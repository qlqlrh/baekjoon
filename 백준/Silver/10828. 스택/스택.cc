#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N; // 명령의 수
    cin >> N;

    stack<int> stk;
    for (int i = 0; i < N; i++) {
        string command;
        cin >> command;

        if (command == "push") {
            int num;
            cin >> num;
            stk.push(num);
        }

        if (command == "top") {
            int top = -1;
            if (stk.size() != 0) {
                top = stk.top();
            }
            cout << top << "\n";
        }
        if (command == "size")
            cout << stk.size() << "\n";

        if (command == "empty") {
            int result = (stk.size() == 0) ? 1 : 0;
            cout << result << "\n";
        }

        if (command == "pop") {
            int top = -1;
            if (stk.size() != 0) {
                top = stk.top();
                stk.pop();
            }
            cout << top << "\n";
        }
    }
}