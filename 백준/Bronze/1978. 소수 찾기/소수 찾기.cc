#include <iostream>
using namespace std;

int main() {
    int N; // 최대 100
    int cnt = 0;
    cin >> N;

    // 소수 : 1과 자기자신으로만 나누어 떨어지는 수
    int num;
    for (int i = 0; i < N; i++) {
        cin >> num;

        int j;
        for (j = 2; j <= 1000; j++) {
            if (num == 1)
                break;
            if ((num != j) && (num % j == 0)) { // 자기 자신이 아닌 배수가 있는 경우 -> 소수X
                break;
            }
        }

        if (j >= 1000) {
            cnt++;
        }
    }

    cout << cnt << endl;

    return 0;
}