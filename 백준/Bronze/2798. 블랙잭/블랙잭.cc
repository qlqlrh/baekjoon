#include <iostream>
#include <vector>
using namespace std;

/**
 * 출력 : M을 넘지 않으면서, 최대한 M에 가까운 카드 3장의 합
 * 구현 : 카드의 최대 개수가 100개라서, 브루투포스 방법으로 풀어도 될 것 같다.
 * 시간복잡도:
 *
 */
int main() {
    int N; // 카드 개수 (3 ~ 100)
    int M; // 카드 합  (10 ~ 300,000)
    cin >> N >> M;

    vector<int> myVec(N);
    for (int i = 0; i < N; i++) {
        cin >> myVec[i]; // 100,000 이하
    }

    int sum = 0; // 3개 숫자 합
    int result = 0;
    int sub = 300000;
    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            for (int k = j+1; k < N; k++) {
                sum += myVec[i] + myVec[j] + myVec[k];
                if (sum > M) {
                    sum = 0;
                    continue;
                }
                if (M - sum < sub) {
                    sub = M - sum;
                    result = sum;
                }
                sum = 0;
            }
        }
    }

    cout << result << endl;

}