#include <iostream>
using namespace std;

// N번째 종말의 수 출력하기
// 종말의 수란, 6이 최소 3개 이상 연속으로 들어가는 수

int main() {
    int N;
    cin >> N; // 10,000보다 작거나 같은 자연수

    int cnt = 0;
    int result = 666;

    while (true) {
        if (to_string(result).find("666") != string::npos) { // result 안에 666이 있다면 찾았다면
            cnt += 1;
        }

        if (cnt == N)
            break;

        result += 1;
    }

    cout << result << endl;
}

// Brute Force 알고리즘