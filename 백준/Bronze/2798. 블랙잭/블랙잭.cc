#include <iostream>
#include <vector>
using namespace std;

/**
 * 출력 : M을 넘지 않으면서, 최대한 M에 가까운 카드 3장의 합
 * 구현 : 카드의 최대 개수가 100개라서, 브루투포스 방법으로 풀어도 될 것 같다.
 *       가능한 모든 조합을 보면 하나씩 찾아보면 되므로, 0, 1, 2번째 숫자 조합부터 차례대로 조합을 찾는다.
 *       숫자 3개의 합이 M보다 크면 제외하고,
 *       아닌 경우에 대해서만 M과의 차이가 가장 적은 합을 구한다.
 * 시간복잡도: N까지의 for문이 3개 중첩되어 있으므로, O(N^3)이다.
 *          하지만 N이 최대 100이기 때문에 1,000,000이므로, 1초 안에 연산이 가능하다.
 * 개선할 점 : STL을 더 많이 사용하자!
 */
int main() {
    int N; // 카드 개수 (3 ~ 100)
    int M; // 카드 합  (10 ~ 300,000)
    cin >> N >> M;

    vector<int> myVec(N);
    for (int i = 0; i < N; i++) {
        cin >> myVec[i]; // 100,000 이하
    }

    int result = 0;
    int sub = 300000;
    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            for (int k = j+1; k < N; k++) {
                int sum = myVec[i] + myVec[j] + myVec[k];
                if (sum > M) {
                    continue;
                }
                if (M - sum < sub) { // <- STL 사용 가능
                    sub = M - sum;
                    result = sum;
                }
            }
        }
    }

    cout << result << endl;

}
