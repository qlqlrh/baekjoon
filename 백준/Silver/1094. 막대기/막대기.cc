#include <iostream>
using namespace std;

int X; // 만들고 싶은 막대 길이
int cnt = 1; // 붙인 막대 개수
int lenth = 64; // 초기 막대 길이

int main() {
    cin >> X;
    
    // 1. 막대 자르기
    while (lenth >= X) {
        if (lenth == X) {
            cout << cnt << endl;
            exit(0);
        }
        lenth /= 2;
    }

    // 2. X 길이 만들기
    X -= lenth;
    while (X > 0) {
        lenth /= 2;
        if (X >= lenth) {
            X -= lenth;
            cnt += 1;
        }
    }
    cout << cnt << endl;
}