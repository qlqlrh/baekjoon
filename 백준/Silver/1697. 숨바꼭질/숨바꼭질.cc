#include <bits/stdc++.h>

using namespace std;

int N; // 수빈이의 현재 위치
int K; // 동생의 현재 위치
int dist[600000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;

    int minTime = INT_MAX;
    fill(dist, dist+600000, -1);

    queue<int> q;
    q.push(N);
    dist[N] = 0;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        if (cur > 200000) continue;
        if (cur == K)
            minTime = min(minTime, dist[cur]);
        if (dist[cur + 1] < 0) {
            q.push(cur + 1);
            dist[cur + 1] = dist[cur] + 1;
        }
        if (dist[cur - 1] < 0) {
            q.push(cur - 1);
            dist[cur - 1] = dist[cur] + 1;
        }
        if (dist[2 * cur] < 0) {
            q.push(2 * cur);
            dist[2 * cur] = dist[cur] + 1;
        }
    }

    cout << minTime;
}