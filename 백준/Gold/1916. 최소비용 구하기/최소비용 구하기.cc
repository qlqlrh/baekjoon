#include <bits/stdc++.h>

using namespace std;

// 문제 조건: 도시(N) 최대 1,000개, 버스(M) 최대 100,000개
// 비용은 0 이상 100,000 미만. 최단 거리는 int 범위를 넘지 않음 (약 1억 이하)
const int INF = 1e9; // 충분히 큰 값으로 초기화

int N, M;
int startCity, endCity;
vector<pair<int, int>> adj[1001]; // 인접 리스트: adj[출발노드] = {cost, 도착노드}
int dist[1001]; // 시작점으로부터의 최단 거리를 저장할 배열

void dijkstra(int start) {
    // 1. 모든 거리를 무한대로 초기화
    fill(dist, dist + N + 1, INF);
    
    // 2. 우선순위 큐 정의 (최소 힙: 비용이 적은 것이 top으로 오게 함)
    // pair<비용, 노드번호> 순서로 저장
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    // 시작 노드 설정
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int current_dist = pq.top().first;
        int curr = pq.top().second;
        pq.pop();

        // 3. 이미 처리된 적 있는 노드라면 무시 (최적화의 핵심)
        if (dist[curr] < current_dist) continue;

        // 4. 인접한 노드들을 확인
        for (auto &edge : adj[curr]) {
            int next_node = edge.second;
            int cost_to_next = edge.first;

            // 현재 노드를 거쳐서 가는 것이 더 빠르다면 갱신
            if (dist[next_node] > dist[curr] + cost_to_next) {
                dist[next_node] = dist[curr] + cost_to_next;
                pq.push({dist[next_node], next_node});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v}); // 간선 정보 저장
    }

    cin >> startCity >> endCity;

    dijkstra(startCity);

    // 결과 출력: 시작 도시에서 도착 도시까지의 최소 비용
    cout << dist[endCity] << "\n";

    return 0;
}