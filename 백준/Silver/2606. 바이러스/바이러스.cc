#include <bits/stdc++.h>

using namespace std;

// 유형 : BFS, 방향없는 그래프

int main() {

    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N; // 컴퓨터의 수 (100 이하)
    int M; // 직접 연결되어 있는 컴퓨터 쌍의 수
    cin >> N;
    cin >> M;

    vector<vector<int>> v(N + 1);
    vector<bool> vis(N + 1);

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;

        v[a].push_back(b);
        v[b].push_back(a);
    }

    // 메인 로직
    int cnt = 0;
    queue<int> q;
    vis[1] = true;
    q.push(1);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int node : v[cur]) {
            if (vis[node]) { // 이미 방문한 노드
                continue;
            }
            else { // 방문 안 한 노드만 push
                cnt++;
                vis[node] = true;    
                q.push(node);
            }
        }
    }

    // 결과 출력
    cout << cnt << "\n";
}