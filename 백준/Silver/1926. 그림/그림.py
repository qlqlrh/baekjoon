import sys
from collections import deque
input = sys.stdin.readline

n ,m = map(int, input().split())
data = [list(map(int, input().split())) for _ in range(n)]
vis = [[False] * m for _ in range(n)]
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

def bfs(x, y):
    dq = deque()
    dq.append((x, y))
    vis[x][y] = True

    area = 1
    while len(dq) > 0:
        a, b = dq.pop()
        for i in range(4):
            nx = a + dx[i]
            ny = b + dy[i]

            if nx < 0 or nx >= n or ny < 0 or ny >= m:
                continue

            # 그림 영역 계산 (방문X면서 1이어야 함)
            if not vis[nx][ny] and data[nx][ny] == 1:
                area += 1
                vis[nx][ny] = True
                dq.append((nx, ny))
    return area

cnt = 0
max_area = 0
for i in range(n):
    for j in range(m):
        # bfs 시작점 찾기 (방문X 면서 1이어야 함)
        if not vis[i][j] and data[i][j] == 1:
            cnt += 1
            area = bfs(i, j)
            max_area = max(area, max_area)

sys.stdout.write("\n".join(map(str, [cnt, max_area])))