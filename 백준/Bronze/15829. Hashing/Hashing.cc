#include <iostream>
#include <vector>
#include <cmath>
#define R 31
#define M 1234567891
using namespace std;

/**
 * 출력 : 해시 값을 정수로 출력
 * 구현 : 주어진 해시 함수 수식에 맞춰 대입하면 될 것 같다. r = 31, M = 1234567891로 설정.
 * 시간복잡도 : L에 대해서 단일 for문을 돌기 때문에 O(1)이다.
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

    int hash = 0; // 1,234,567,891 보다 작으므로 int형 가능
    for (int i = 0; i < L; i++) {
        hash += numList[i] * pow(R, i);
    }

    hash %= M;

    cout << hash << endl;

}