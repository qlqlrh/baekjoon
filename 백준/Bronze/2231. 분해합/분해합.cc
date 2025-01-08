#include <iostream>
using namespace std;

/**
 * 시간 제한 : 2초
* 시간 복잡도 : O(N * logN), 최대 약 6,000,000번의 연산이 필요하므로 2초 내로 연산이 가능하다
 * 구현 : 생성자가 1인 경우부터 N-1인 경우까지 모두 확인해봐야 하는 문제이다.
 *       처음에 이중 while문으로 구현하였다가 조금 더 효율적으로 짜기 위해 for문 + while문 형태로 바꾸었다.
 */
int main() {

    int N; // 최대 1,000,000
    cin >> N;

    int result = 0; // 생성자

    for (int i = 1; i < N; i++) { // N의 생성자는 N보다 작으므로 N -1까지 반복
        int sum = i;
        int num = i;

        while (num > 0) { // 각 자리수 합 계산
            sum += num % 10;
            num /= 10;
        }

        if (sum == N) {
            result = i;
            break;
        }
    }

    cout << result << endl;

    return 0;

}