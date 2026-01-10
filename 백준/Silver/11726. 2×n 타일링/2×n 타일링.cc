#include <bits/stdc++.h>

using namespace std;

// 문제 유형 : 수학인 줄 알았으나, DP....

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N; // 1000 이하
    cin >> N;

    int D[1002];
    D[1] = 1;
    D[2] = 2;
    for (int i = 3; i <= N; i++) {
        D[i] = (D[i-1] + D[i-2]) % 10007;
    }

    cout << D[N] << "\n";
}