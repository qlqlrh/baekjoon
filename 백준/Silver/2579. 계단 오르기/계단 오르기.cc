#include <bits/stdc++.h>

using namespace std;

int D[301][3];

// 유형 : DP

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N; // 계단의 개수 (300 이하)
    cin >> N;

    // 입력 받기
    vector <int> v(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> v[i];
    }

    if (N == 1) {
        cout << v[1] << endl;
        return 0;
    }

    D[1][1] = v[1];
    D[1][2] = 0;
    D[2][1] = v[2];
    D[2][2] = v[1] + v[2];

    for (int i = 3; i <= N; i++) {
        D[i][1] = max(D[i - 2][1], D[i-2][2]) + v[i];
        D[i][2] = D[i - 1][1] + v[i];
    }

    cout << max(D[N][1], D[N][2]) << endl;



}