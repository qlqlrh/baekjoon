#include <bits/stdc++.h>
#define pn(x) cout << x << "\n";
#define listPn(x) for (auto y : x) cout << y << " " ; cout << "\n";

using namespace std;

// 유형 : 백트래킹

int N, M;
vector<int> v;
vector<int> result;
set<vector<int>> final;

void backtrack() {
    if (result.size() == M) {
        // listPn(result);
        final.insert(result);
        return;
    }

    for (int i = 0; i < N; i++) {
        // 예외 조건 (앞에 있는 것보다 작은 건 push 불가)
        if (!result.empty() && (v[i] < result.back())) continue;

        result.push_back(v[i]);
        backtrack();
        result.pop_back();
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N >> M;
    v.resize(N);
    for (int i = 0; i < N; i++) cin >> v[i];

    sort(v.begin(), v.end());
    backtrack();

    for (auto vec : final) {
        listPn(vec);
    }
}