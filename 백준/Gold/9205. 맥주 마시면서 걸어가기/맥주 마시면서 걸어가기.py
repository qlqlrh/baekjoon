# 상태 BFS
from collections import deque

t = int(input()) # 테스트 케이스 개수
for _ in range(t):
    beers = 20
    n = int(input()) # 편의점 개수
    nodes = [] # (x,y), 집, 편의점1, 2, ... , 축제
    nodes.append(list(map(int, input().split()))) # 상근이네 집 좌표
    for i in range(n):
        nodes.append(list(map(int, input().split())))
    nodes.append(list(map(int, input().split()))) # 페스티벌 좌표
    # print(nodes)

    visited = [False] * (n + 2)
    q = deque([0]) # 집 추가
    visited[0] = True

    while q:
        cur = q.popleft()
        if cur == n + 1: # 축제
            break
        for nxt in range(n + 2):
            if visited[nxt]:
                continue
            # 맨해튼 거리
            dist = abs(nodes[cur][0] - nodes[nxt][0]) + abs(nodes[cur][1] - nodes[nxt][1])
            if dist <= 1000: # 거리가 1000 이하면 이동 가능
                q.append(nxt)
                visited[nxt] = True
    print("happy" if visited[n + 1] else "sad")