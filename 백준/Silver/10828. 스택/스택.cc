#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N; // 명령의 수
    cin >> N;

    vector<int> v;
    for (int i = 0; i < N; i++) {
        string command;
        int num;
        cin >> command;

        if (command == "push") {
            cin >> num;
            v.push_back(num);
        }

        else if (command == "pop") {
            if (!v.empty()) {
                cout << v.back() << endl;
                v.pop_back();
            } else {
                cout << "-1\n";
            }
        }

        else if (command == "size") {
            cout << v.size() << endl;
        }

        else if (command == "empty") {
            if (v.empty()) cout << "1\n";
            else           cout << "0\n";
        }

        if (command == "top") {
            if (v.empty()) cout << "-1\n";
            else           cout << v.back() << endl;
        }
    }

    return 0;
}