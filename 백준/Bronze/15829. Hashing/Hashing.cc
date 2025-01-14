#include <iostream>
#include <vector>
using namespace std;

#define R 31
#define M 1234567891

/**
 * 출력 : 해시 값을 정수로 출력
 * 구현 : 주어진 해시 함수 수식에 맞춰 대입하면 될 것 같다. r = 31, M = 1234567891로 설정.
 * 시간복잡도 : L에 대해서 단일 for문을 돌기 때문에 O(L)이다.
 * 개선할 점 : pow 함수를 써서 계산을 하려고 했는데,
 *           이는 부동소수점 연산을 해서 R 값이 클 경우, 반환값이 부정확할 수 있다고 한다.
 *           몰랐던 부분이라 다음에 pow 함수를 사용할 때 주의해야겠다!
 */
int main() {
    int L; // 1 ~ 5  or 1 ~ 50
    cin >> L;

    vector<int> numList(L);
    for (int i = 0; i < L; i++) {
        char myChar;
        cin >> myChar;
        numList[i] = myChar - 'a' + 1;
    }

    long long hash = 0;
    long long power = 1;
    for (int i = 0; i < L; i++) {
        hash = (hash + numList[i] * power) % M; // pow 함수 쓰면 X
        power = (power * R) % M;
    }

    cout << hash << endl;

}