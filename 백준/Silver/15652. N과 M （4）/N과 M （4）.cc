#define pnt(x) cout << x << "\n";
#define listPnt(x) for (auto y : x) cout << y << "\n";
#include <bits/stdc++.h>

using namespace std;

// 유형 : 백트래킹? (N이 작아서)
int N, M; // 1 ≤ M ≤ N ≤ 8
vector<int> result;

void backtrack(int start) {
    if (result.size() == M) {
        listPnt(result);
        return;
    }

    for (int i = start; i <= N; i++) {
        result.push_back(i);
        backtrack(i);
        result.pop_back();
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N >> M;

    backtrack(1);
}