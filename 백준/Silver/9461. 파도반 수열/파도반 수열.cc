#include <bits/stdc++.h>

using namespace std;

// 문제 유형 : 규칙 찾기, 1-index (DP?)

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int T; // 테스트 케이스
    cin >> T;

    while (T--) {
        int N; // 100 이하
        cin >> N;

        // 값 초기화
        long long D[102] = {0, 1, 1, 1, 2, 2};
        if (N <= 5) {
            cout << D[N] << "\n";
            continue;
        }

        // 점화식 : D[n] = D[n-3] + D[n-2] (n >= 6)
        for (int i = 6; i <= N; i++) {
            D[i] = D[i - 3] + D[i - 2];
        }

        cout << D[N] << "\n";
    }
}