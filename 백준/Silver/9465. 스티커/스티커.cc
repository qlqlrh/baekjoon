#include <bits/stdc++.h>
#define pn(x) cout << x << "\n"
#define listPn(x) for (auto y : x) cout << y << " "; cout << "\n"

using namespace std;

// 유형 : DP? (이전 행/열의 스티커를 선택했냐 안 했냐의 정보가 필요함)
// dp[i][j][0] : i행 j열 스티커를 선택 안 했을 때의 최대 점수
// dp[i][j][1] : i행 j열 스티커를 선택 했을 때의 최대 점수
// dp[0][0][0] = 0
// dp[0][0][1] = v[0][0]
// dp[1][0][0] = 0
// dp[1][0][1] = v[1][0]
// dp[0][1][0] = max(dp[0][0][1], dp[1][0][1])
// dp[0][1][1] = max(dp[1][0][0], dp[1][0][1])
//

int T;
int N; // 100,000 이하

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> T;
    while (T--) {
        cin >> N;
        vector<int> v[2];
        for (int j = 0; j < 2; j++) {
            for (int i = 0; i < N; i++) {
                int score; // 100 이하
                cin >> score;
                v[j].push_back(score);
            }
        }
        // listPn(v[0]);

        int dp[2][N][2];
        dp[0][0][0] = 0;
        dp[0][0][1] = v[0][0];
        dp[1][0][0] = 0;
        dp[1][0][1] = v[1][0];

        for (int j = 1; j < N; j++) {
            // 0행 j열 스티커를 선택 안 했을 때의 최댓값
            dp[0][j][0] = max(dp[0][j-1][0], dp[0][j-1][1]);
            dp[0][j][0] = max(dp[0][j][0], dp[1][j-1][0]);
            dp[0][j][0] = max(dp[0][j][0], dp[1][j-1][1]);

            // cout << "j : " << j << ", dp[0][j][0] : " << dp[0][j][0] << "\n";

            // 0행 j열 스티커를 선택했을 때의 최댓값
            dp[0][j][1] = max(dp[0][j-1][0], dp[1][j-1][0]);
            dp[0][j][1] = max(dp[0][j][1], dp[1][j-1][1]);
            dp[0][j][1] += v[0][j];

            // 1행 j열 스티커를 선택 안 했을 때의 최댓값
            dp[1][j][0] = dp[0][j][0];

            // 1행 j열 스티커를 선택했을 때의 최댓값
            dp[1][j][1] = max(dp[0][j-1][0], dp[1][j-1][0]);
            dp[1][j][1] = max(dp[1][j][1], dp[0][j-1][1]);
            dp[1][j][1] += v[1][j];
        }

        int selectMax = max(dp[0][N-1][1], dp[1][N-1][1]);
        int unselectMax = max(dp[0][N-1][0], dp[1][N-1][0]);
        cout << max(selectMax, unselectMax) << "\n";
    }
}