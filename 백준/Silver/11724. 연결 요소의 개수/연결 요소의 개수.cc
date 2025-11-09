#include <bits/stdc++.h>

using namespace std;

int N; // node 개수
int M; // edge 개수
vector<int> adj[1001]; // 그래프 정보
bool vis[1001];

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // 방향 없는 그래프니까 반대로도 넣어주기
    }

    int cnt = 0; // 그래프 component 개수
    // BFS
    for (int i = 1; i <= N; i++) {
        queue<int> q;
        if (vis[i]) continue;
        q.push(i);
        vis[i] = true;
        cnt++;

        while (!q.empty()) {
            int current = q.front();
            q.pop();
            for (int next : adj[current]) {
                if (vis[next]) continue;
                q.push(next);
                vis[next] = true;
            }
        }
    }

    cout << cnt;

}