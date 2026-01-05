#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int M; // 수행해야 하는 연산의 수
    cin >> M;

    int mask = 0;
    for (int i = 0; i < M; i++) {
        string command;
        int number;
        cin >> command;
        if (command == "add") {
            cin >> number;
            mask |= ( 1 << (number-1) );
        }
        else if (command == "remove") {
            cin >> number;
            mask &= ~( 1 << (number-1) );
        }
        else if (command == "check") {
            cin >> number;
            if (mask & (1 << (number-1))) {
                cout << "1\n";
            }
            else { cout << "0\n"; }
        }
        else if (command == "toggle") {
            cin >> number;
            mask ^= ( 1 << (number-1) );
        }
        else if (command == "all") {
            mask = 0b11111111111111111111;
        }
        else if (command == "empty") {
            mask = 0;
        }
    }
}