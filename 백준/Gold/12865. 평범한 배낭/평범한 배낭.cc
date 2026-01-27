#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    vector<int> W(N + 1), V(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> W[i] >> V[i];
    }

    // dp[w] = 무게 합이 w일 때 얻을 수 있는 최대 가치
    vector<int> dp(K + 1, 0);

    for (int i = 1; i <= N; i++) {
        // 0-1 배낭이므로 뒤에서 앞으로 순회해야 같은 물건을 여러 번 쓰지 않음
        for (int w = K; w >= W[i]; w--) {
            dp[w] = max(dp[w], dp[w - W[i]] + V[i]);
        }
    }

    cout << dp[K] << '\n';
    return 0;
}