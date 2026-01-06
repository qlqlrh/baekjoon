#include <bits/stdc++.h>

using namespace std;

int N; // 1 ≤ N ≤ 10
int K; // 1 ≤ K ≤ 100,000,000

// 문제 유형 : 브루트포스?

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    // 1. 입력 받기
    cin >> N >> K;
    vector<int> v(N + 1);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    // 3. 모든 조합 돌면서 최소 동전 개수 찾기
    int cnt = 0;
    for (int i = N - 1; i >= 0; --i) {
        cnt += K / v[i];
        K %= v[i];
    }

    cout << cnt << "\n";
}