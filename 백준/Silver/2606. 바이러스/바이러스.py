# 연결 그래프 (컴포넌트 분리, 개수 세기)
from collections import deque

V = int(input())
E = int(input())

graph = [[] for _ in range((V + 1))]
for _ in range(E):
    v1, v2 = map(int, input().split())
    graph[v1].append(v2)
    graph[v2].append(v1)

visited = [False] * (V + 1)
q = deque([1])
visited[1] = True
cnt = 0
while q:
    u = q.popleft()
    for v in graph[u]:
        if not visited[v]:
            q.append(v)
            visited[v] = True
            cnt += 1

print(cnt)