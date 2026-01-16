#include <bits/stdc++.h>
#define pnt(x) cout << x << "\n"
#define listPnt(x) for (auto y : x) cout << y << " "; cout << "\n"

using namespace std;

// 시작 시간 : 2시 30분
// 종료 시간 : 2:47
// 유형 : 백트래킹
// 질문 : set은 정렬되는 게 자동 옵션인가? unordered_set은 아니고?

int N, M; // 1 ≤ M ≤ N ≤ 8
vector<int> v;
vector<int> result;
vector<bool> used;

void backtrack() {
    if (result.size() == M) {
        listPnt(result);
        return;
    }

    int prev = -1; // 같은 깊이에서 이전에 선택한 값
    for (int i = 0; i < N; i++) {
        // 이미 사용한 인덱스는 건너뛰기
        if (used[i]) continue;
        // 같은 깊이에서 이전에 선택한 값과 같으면 건너뛰기 (중복 수열 방지)
        if (prev == v[i]) continue;
        
        used[i] = true;
        result.push_back(v[i]);
        prev = v[i]; // 현재 선택한 값을 prev에 저장
        backtrack();
        result.pop_back();
        used[i] = false;
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N >> M;

    v.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());
    used.resize(N, false);
    backtrack();
}