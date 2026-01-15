#include <bits/stdc++.h>

#define pnt(x) cout << x << "/n";
#define listPnt(x) for (auto y : x) cout << y << " ";

using namespace std;

int N, M; // 1 ≤ M ≤ N ≤ 8
vector<int> result;

// 유형 : 백트래킹

void backtrack(int start, const vector<int>& vec) {
    if (result.size() == M) {
        listPnt(result);
        cout << "\n";
        return;
    }

    for (int num : vec) {
        if (!result.empty() && num == result.back()) continue;
        if (find(result.begin(), result.end(), num) != result.end()) continue;
        result.push_back(num);
        backtrack(start + 1, vec);
        result.pop_back();
    }
}


int main() {

    cin >> N >> M;

    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    backtrack(v[0], v);
}