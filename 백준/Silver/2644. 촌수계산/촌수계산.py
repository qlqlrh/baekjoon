# 연결 그래프
# dist 배열
# 그냥 BFS
# 출력 : v1, v2 사이의 촌수 (친척이 아니면 -1)

from collections import deque

V = int(input())
v1, v2 = map(int, input().split())
E = int(input())

graph = [[] for _ in range(V + 1)]
for i in range(E):
    x, y = map(int, input().split()) # 부모, 자식
    graph[x].append(y)
    graph[y].append(x)

dist = [-1] * (V + 1)

q = deque([v1])
dist[v1] = 0

while q:
    u = q.popleft()
    for v in graph[u]:
        if dist[v] == -1: # 방문 안 했다는 뜻
            dist[v] = dist[u] + 1
            q.append(v)

print(dist[v2])