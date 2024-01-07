#include <iostream>
using namespace std;

// * 다리 개수가 아니라 경우의 수 구하는 문제임
// * 조합 이용

int T; // 테스트케이스 개수
int N, M; // 서쪽, 동쪽 사이트의 개수

long long combination(int n, int m) {
    long long result = 1;
    int down = 1;
    for (int i = n; i > n - m; i--) { // m번 반복
        result *= i;
        result /= down;
        down++;
    }
    return result;
    
    // 안 되는 코드
    // long long result = 1;
    // int up = n;
    // for (int i = m; i > 0; i--) { // m번 반복
    //     result *= up;
    //     result /= i;
    //     up--;
    // }
    // return result;
}

int main() {
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N >> M;
        if (N > M)
            cout << combination(N, M) << endl;
        else if (M > N)
            cout << combination(M, N) << endl;
        else if (N == 0 || M == 0 || N == M)
            cout << "1" << endl;
    }
}

// ** 팩토리얼 계산 다하고 나누면 0 나옴.
// ** 분모 m번 곱하고 분자 m번 나누는 식으로 풀이
// ** 분자를 1부터 나눠야 약분이 돼서 값이 제대로 나옴..