#include <iostream>
#include <cmath>
using namespace std;

/** 수정사항
 * 1. 입력되는 숫자는 1000까지지만, sqrt(num)까지만 검사해도 소수 판별 가능
 *    즉, num=36이라면, 2부터 6까지만 나눠보면 된다는 뜻
 */

int main() {
    int N; // 최대 100
    int cnt = 0;
    cin >> N;

    // 소수 : 1과 자기자신으로만 나누어 떨어지는 수
    int num;
    for (int i = 0; i < N; i++) {
        cin >> num;

        if (num == 1)
            continue;

        bool isPrime = true;
        for (int j = 2; j <= sqrt(num); j++) {
            if (num % j == 0) { // 자기 자신이 아닌 배수가 있는 경우 -> 소수X
                isPrime = false;
                break;
            }
        }

        if (isPrime) {
            cnt++;
        }
    }

    cout << cnt << endl;

    return 0;
}
