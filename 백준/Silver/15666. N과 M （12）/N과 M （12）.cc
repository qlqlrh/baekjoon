#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> v;
vector<int> result;

void backtrack(int start) {
    if (result.size() == M) {
        for (int i = 0; i < M; i++) {
            cout << result[i] << " ";
        }
        cout << "\n";
        return;
    }

    int prev = -1;  // 같은 depth에서 이전에 선택한 값
    for (int i = start; i < N; i++) {
        if (prev == v[i]) continue;  // 같은 depth에서 같은 숫자 스킵
        
        result.push_back(v[i]);
        backtrack(i);  // 중복 선택 허용이므로 i부터 시작
        result.pop_back();
        
        prev = v[i];
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N >> M;
    v.resize(N);
    for (int i = 0; i < N; i++) cin >> v[i];

    sort(v.begin(), v.end());
    // 입력 중복 제거 (선택사항이지만 효율적)
    v.erase(unique(v.begin(), v.end()), v.end());
    N = v.size();
    
    backtrack(0);
}