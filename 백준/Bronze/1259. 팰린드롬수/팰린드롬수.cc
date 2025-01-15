#include <iostream>
using namespace std;

/**
 * 출력: 팰린드롬수 판단 (yes or no)
 * 구현:
 * 시간복잡도:
 */
int main() {

    while (true) {
        int num;
        cin >> num;

        if (num == 0) break;

        string numStr = to_string(num);
        int len = numStr.length();
        bool isPalin = true;
        for (int i = 0; i < len / 2; i++) {
            if (numStr[i] != numStr[len - 1 - i]) {
                isPalin = false;
                break;
            }
        }

        cout << (isPalin ? "yes" : "no") << endl;
    }
}