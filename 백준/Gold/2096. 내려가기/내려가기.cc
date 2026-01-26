#include <bits/stdc++.h>

using namespace std;

// 유형 : DP
// dp[i][0] : 이전 행에서 i번째 열을 선택했을 때 최댓값
// dp[i][1] : 이전 행에서 i번째 열을 선택했을 때 최솟값
// d[i][0] = d[i-1][0] + max({v[i-1], v[i], v[i+1]} // i 값에 따라 분기
// d[i][0] = d[i-1][0] + min({v[i-1], v[i], v[i+1]} // i 값에 따라 분기

int N; // 100,000 이하
int dp[3][2];


int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> N;

    for (int i = 0; i < N; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (i == 0) {
            dp[0][0] = a;
            dp[1][0] = b;
            dp[2][0] = c;

            dp[0][1] = a;
            dp[1][1] = b;
            dp[2][1] = c;
        }
        else {
            int maxA = max(dp[0][0], dp[1][0]) + a;
            int maxB = max({dp[0][0], dp[1][0], dp[2][0]}) + b;
            int maxC = max(dp[1][0], dp[2][0]) + c;
            dp[0][0] = maxA;
            dp[1][0] = maxB;
            dp[2][0] = maxC;

            int minA = min(dp[0][1], dp[1][1]) + a;
            int minB = min({dp[0][1], dp[1][1], dp[2][1]}) + b;
            int minC = min(dp[1][1], dp[2][1]) + c;
            dp[0][1] = minA;
            dp[1][1] = minB;
            dp[2][1] = minC;
        }
    }

    cout << max({dp[0][0], dp[1][0], dp[2][0]}) << " " << min({dp[0][1], dp[1][1], dp[2][1]}) << "\n";
}