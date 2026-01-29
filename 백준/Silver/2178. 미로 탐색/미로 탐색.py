"""
BOJ 2178 미로 탐색
- (1,1) → (N,M) 최소 칸 수 (시작·도착 포함)
- BFS로 최단 거리 계산
"""
import sys
from collections import deque
input = sys.stdin.readline

N, M = map(int, input().split())
maze = []
for _ in range(N):
    maze.append([int(c) for c in input().rstrip()])

# dist[i][j]: (0,0) → (i,j) 최소 칸 수 (도달 전이면 -1 또는 미방문 처리)
dist = [[-1] * M for _ in range(N)]
dist[0][0] = 1  # 시작 칸 포함

# 상하좌우
dr = [-1, 1, 0, 0]
dc = [0, 0, -1, 1]

q = deque([(0, 0)])
while q:
    r, c = q.popleft()  # BFS: 먼저 도달한 것부터 처리 → 최단 거리 보장, DFS는 최단거리 보장 X
    if r == N - 1 and c == M - 1:
        break

    for i in range(4):
        nr, nc = r + dr[i], c + dc[i]
        if nr < 0 or nr >= N or nc < 0 or nc >= M:
            continue
        if maze[nr][nc] != 1 or dist[nr][nc] != -1:
            continue
        dist[nr][nc] = dist[r][c] + 1
        q.append((nr, nc))

print(dist[N - 1][M - 1])