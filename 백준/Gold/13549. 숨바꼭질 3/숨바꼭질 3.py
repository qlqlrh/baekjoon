"""
백준 13549 - 숨바꼭질 3
0-1 BFS: 비용 0(순간이동)은 덱 앞에, 비용 1(걷기)은 덱 뒤에 넣어 최단 시간 보장.
"""
from collections import deque

N, K = map(int, input().split())
MAX = 200_001  # 순간이동으로 100000 넘어갈 수 있음

dist = [-1] * MAX
dist[N] = 0
dq = deque([N])

while dq:
    x = dq.popleft()
    if x == K:
        print(dist[x])
        break

    # 비용 0: 순간이동 → 앞에 넣어서 먼저 처리
    nxt = 2 * x
    if nxt < MAX and dist[nxt] == -1:
        dist[nxt] = dist[x]
        dq.appendleft(nxt)

    # 비용 1: 걷기 → 뒤에 넣기
    for nxt in (x - 1, x + 1):
        if 0 <= nxt < MAX and dist[nxt] == -1:
            dist[nxt] = dist[x] + 1
            dq.append(nxt)
