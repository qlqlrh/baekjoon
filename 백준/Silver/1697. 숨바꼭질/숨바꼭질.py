import sys
from collections import deque
input = sys.stdin.readline

N, K = map(int, input().split())
dist = [-1] * 200000


"""
백트래킹? BFS?
x -> x+1 or x-1 or 2*X
큐에 N 넣고, pop하고, x+1, x-1, 2*X 넣고, 거리 업데이트.
단, 방문 안 해본 점일 때만. (dist[i] == -1 일 때만)
dist 배열 사용
그리고 pop 햇을 떄 K이면, 중지
"""

q = deque()
q.append(N)
dist[N] = 0

while q:
    cur = q.popleft()
    if cur == K:
        break
    if cur - 1 >= 0 and dist[cur - 1] == -1:
        q.append(cur - 1)
        dist[cur - 1] = dist[cur] + 1
    if cur + 1 <= 100000 and dist[cur + 1] == -1:
        q.append(cur + 1)
        dist[cur + 1] = dist[cur] + 1
    if 2 * cur <= 100000 and dist[2 * cur] == -1:
        q.append(2 * cur)
        dist[2 * cur] = dist[cur] + 1

print(dist[K])