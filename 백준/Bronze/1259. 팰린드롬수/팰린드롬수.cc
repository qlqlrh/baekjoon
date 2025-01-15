#include <iostream>
using namespace std;

/**
 * 출력: 팰린드롬수 판단 (yes or no)
 * 구현:
 * 시간복잡도:
 */
int main() {

    while (true) {
        string num;
        cin >> num;

        if (num == "0") break;

        int len = num.length();
        string isPalin = "yes";
        for (int i = 0; i < len/2; i++) {
            if (num[i] != num[len-1-i]) {
                isPalin = "no";
                break;
            }
        }

        cout << isPalin << endl;
    }
}