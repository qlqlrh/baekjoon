#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    set<int> numbers;
    int M; // 수행해야 하는 연산의 수
    cin >> M;

    for (int i = 0; i < M; i++) {
        string command;
        cin >> command;
        if (command == "add") {
            int number;
            cin >> number;
            numbers.insert(number);
        }
        else if (command == "remove") {
            int number;
            cin >> number;
            numbers.erase(number);
        }
        else if (command == "check") {
            int number;
            cin >> number;
            if (numbers.find(number) != numbers.end()) {
                cout << "1\n";
            }
            else { cout << "0\n"; }
        }
        else if (command == "toggle") {
            int number;
            cin >> number;
            if (numbers.find(number) != numbers.end()) {
                numbers.erase(number);
            }
            else { numbers.insert(number); }
        }
        else if (command == "all") {
            numbers
                    = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
                        11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };
        }
        else if (command == "empty") {
            numbers.clear();
        }
    }
}