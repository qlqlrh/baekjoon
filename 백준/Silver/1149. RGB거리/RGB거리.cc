#include <bits/stdc++.h>
#define listPn(x) for(auto y : x) cout << y.second << "(" << y.first << ") "; cout << "\n"

using namespace std;

// 유형 : 백트래킹(x), DP(o)
// 시간 : 2:44 ~
int N;
vector<int> R, G, B;
// vector<bool> used;


int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N;

    R.resize(N);
    G.resize(N);
    B.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> R[i] >> G[i] >> B[i];
    }

    int D[1001][3];
    D[0][0] = R[0];
    D[0][1] = G[0];
    D[0][2] = B[0];
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            if (j == 0) { // R
                D[i][j] = min(D[i-1][1], D[i-1][2]) + R[i];
            }
            else if (j == 1) { // G
                D[i][j] = min(D[i-1][2], D[i-1][0]) + G[i];
            }
            else { // B
                D[i][j] = min(D[i-1][0], D[i-1][1]) + B[i];
            }
        }
    }

    int minCost = INT_MAX;
    for (int j = 0; j < 3; j++) {
        if (D[N-1][j] < minCost)
            minCost = D[N-1][j];
    }

    cout << minCost << "\n";
}