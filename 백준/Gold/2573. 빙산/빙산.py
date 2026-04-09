# 동시 확산 + 감소 진행 => 배열 복사 시뮬레이션 + BFS
# 출력 : 빙산이 분리되는 최소 시간, 분리 안 되면 0 출력

from collections import deque

"""빙산 컴포넌트 개수 반환"""
def count_component(grid):
    visited = [[False] * M for _ in range(N)]
    q = deque()

    count = 0
    for i in range(N):
        for j in range(M):
            if visited[i][j] or grid[i][j] == 0:
                continue
            q.append((i, j))
            visited[i][j] = True
            count += 1

            while q:
                x, y = q.popleft()
                for dx, dy in [(1, 0), (-1, 0), (0, 1), (0, -1)]:
                    nx, ny = x + dx, y + dy
                    if 0 <= nx < N and 0 <= ny < M and not visited[nx][ny] and grid[nx][ny] != 0:
                        q.append((nx, ny))
                        visited[nx][ny] = True
    return count

"""data[x][y]에서 1년 후에 감소하는 높이 반환"""
def after_year(x, y, grid):
    count = 0
    for dx, dy in [(1, 0), (-1, 0), (0, 1), (0, -1)]:
        nx, ny = x + dx, y + dy
        if 0 <= nx < N and 0 <= ny < M and grid[nx][ny] == 0:
            count += 1
    return count


N, M = map(int, input().split())
data = [[] for _ in range(N)]
for i in range(N):
    data[i] = list(map(int, input().split()))
# print(*data, sep='\n')

year = 0

while True:
    cnt = count_component(data)
    if cnt == 0:
        print(0)
        break
    elif cnt >= 2:
        print(year)
        break

    # 빙하 높이 감소
    new_data = [row[:] for row in data]
    for i in range(N):
        for j in range(M):
            if data[i][j] != 0:
                new_data[i][j] -= after_year(i, j, data)
                if new_data[i][j] < 0:
                    new_data[i][j] = 0
    data = new_data
    year += 1