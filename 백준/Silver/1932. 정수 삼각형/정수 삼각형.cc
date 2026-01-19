#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> dp(N, 0);

    for (int i = 0; i < N; i++) {
        for (int j = i; j >= 0; j--) {
            int x;
            cin >> x;

            if (i == 0 && j == 0) {
                dp[0] = x;
            } else if (j == 0) {
                dp[j] = dp[j] + x;              // 위에서만 내려옴
            } else if (j == i) {
                dp[j] = dp[j - 1] + x;          // 왼쪽 위에서만 내려옴
            } else {
                dp[j] = max(dp[j], dp[j - 1]) + x; // 위 / 왼쪽 위 중 최대
            }
        }
    }

    cout << *max_element(dp.begin(), dp.end()) << "\n";
    return 0;
}