import heapq


N = int(input()) # node
M = int(input()) # edge

# graph[a] : a 도시에서 갈 수 있는 (도시, 비용)
graph = [[] for _ in range(N + 1)]
for _ in range(M):
    start, end, cost = map(int, input().split())
    graph[start].append((end, cost))

start, end = map(int, input().split())
    
# 다익스트라
INF = float('inf')
dist = [INF] * (N + 1) # dist[i] : i 도시와 start 도시까지의 최소 거리
heap = [(0, start)] # cost, node
dist[start] = 0

while heap:
    cost, u = heapq.heappop(heap)

    if dist[u] < cost:
        continue

    for v, d in graph[u]:
        # print(dist[v], dist[u], d)
        if dist[v] > dist[u] + d:
            dist[v] = dist[u] + d
            heap.append((d, v))

print(dist[end])