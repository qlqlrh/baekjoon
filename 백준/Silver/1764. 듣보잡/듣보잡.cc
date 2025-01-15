#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // sort, unique
#include <unordered_set>
using namespace std;

/**
 * 출력: 사람 수 출력, 듣도 보도 못한 사람 명단 사전순으로 출력 (교집합 구하기)
 * 구현: 처음에는 하나의 벡터에 모든 사람을 넣은 후, 중복값을 가지는 사람만 출력하려고 했지만 이렇게 구현하면 O((N+M)^2)의 시간복잡도를 가지게 되어서 시간초과가 난다.
 *      따라서, 보도 못한 사람들을 입력 받을 때 중복검사를 해서 연산 수를 줄여야 한다.
 *      마지막에 sort 필요.
 * 시간복잡도:
 * 배운 점: unordered_set이 내부적으로 해시 테이블을 사용하기 때문에 count 함수가 O(1)의 시간복잡도로 수행된다.
 *        따라서 중복 검사 작업을 위해서는 vector보다는 unordered_set을 사용하는 것이 좋다.
 */
int main() {

    int N; // 듣도 못한 사람의 수 (500,000 이하)
    int M; // 보도 못한 사람의 수 (500,000 이하)
    cin >> N >> M;

    // 1. 듣도 못한 사람 입력 받기
    unordered_set<string> unheard(N);
    for (int i = 0; i < N; i++) {
        string person;
        cin >> person;
        unheard.insert(person);
    }

    // 2. 보도 못한 사람을 입력 받는 동시에, 중복 값 확인
    vector<string> results;
    for (int i = 0; i < M; i++) {
        string person;
        cin >> person;

        // 3. 같은 값이 unheard에 존재하면 해당 person은 듣도 보도 못한 사람!
        if (unheard.count(person)) {
            results.push_back(person);
        }
    }

    // 4. abc 순으로 정렬
    sort(results.begin(), results.end());

    // 5. 출력
    cout << results.size() << endl;
    for (auto result : results) {
        cout << result << endl;
    }
}