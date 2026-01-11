#include <bits/stdc++.h>

using namespace std;

// 문제 유형 : DP?

int main() {

    int N; // 1000 이하
    cin >> N;


    int D[1002];
    D[1] = 1;
    D[2] = 3;

    for (int i = 3; i <= N; i++) {
        D[i] = (D[i - 1] + (D[i -2] * 2) % 10007) % 10007;
    }

    cout << D[N] << "\n";
}