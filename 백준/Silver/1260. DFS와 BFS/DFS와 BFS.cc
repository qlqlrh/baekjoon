#define pnt(x) cout << x << "\n";
#define listPnt(x) for (auto y : x) cout << y << "\n";
#include <bits/stdc++.h>

using namespace std;

// 유형 : DFS, BFS, 양방향
int N; // 정점의 개수 N(1 ≤ N ≤ 1,000)
int M; // 간선의 개수 M(1 ≤ M ≤ 10,000)
int V; // 탐색 시작 정점 번호

vector<int> adj[10002];
bool vis[1002];
queue<int> q;
stack<int> st;

void bfs(int v) {
    vis[v] = true;
    q.push(v);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        cout << cur << " ";
        for (int num : adj[cur]) {
            if (!vis[num]) {
                vis[num] = true;
                q.push(num);
            }
        }
    }
}

void dfs(int v) {
    st.push(v);
    while (!st.empty()) {
        int cur = st.top();
        st.pop();
        if (!vis[cur])
            cout << cur << " ";
        vis[cur] = true;
        for (int num : adj[cur]) {
            if (!vis[num]) {
                st.push(num);
            }
        }
    }
} 


int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N >> M >> V;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // 방문할 수 있는 정점이 여러 개인 경우에는 정점 번호가 작은 것을 먼저 방문 (DFS용)
    for (auto& vec : adj) {
        sort(vec.begin(), vec.end(), greater<>());
    }

    dfs(V);
    cout << "\n";

    fill(vis, vis + N + 1, 0);
    // 방문할 수 있는 정점이 여러 개인 경우에는 정점 번호가 작은 것을 먼저 방문 (BFS용)
    for (auto& vec : adj) {
        sort(vec.begin(), vec.end());
    }
    bfs(V);
}