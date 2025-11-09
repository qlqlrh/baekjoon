#include <bits/stdc++.h>

using namespace std;

int N; // 노드의 개수
vector<int> adj[100001]; // 트리 정보
int vis[100001]; // 방문 정보

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int p[N + 1]; // 부모 노드 정보

    // 루트 노드부터 연결된 노드들 방문
    queue<int> q;
    q.push(1);
    vis[1] = 1;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int i = 0; i < adj[cur].size(); i++) {
            int node = adj[cur][i];
            if (vis[node]) { // 트리구조에서 방문했으면 부모 노드
                p[cur] = node;
                continue;
            }
            q.push(node);
            vis[node] = 1;
        }
    }

    for (int i = 2; i <= N; i++) {
        cout << p[i] << "\n";
    }

    return 0;
}