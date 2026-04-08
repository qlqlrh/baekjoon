# 저장해야 될 것 : result = [area1, ... ]
# 그냥 BFS
from collections import deque

N = int(input())
data = [[] for _ in range(N)] # N x N

for i in range(N):
    inp = input()
    for c in inp:
     data[i].append(int(c))

result = []
visit = [[False] * N for _ in range(N)]

for i in range(N):
    for j in range(N):
        if visit[i][j] or data[i][j] == 0:
            continue

        q = deque([(i , j)])
        visit[i][j] = True
        area = 1
        while q:
            x, y = q.popleft()
            for ndx, ndy in [(1,0), (-1, 0), (0, 1), (0, -1)]:
                nx, ny = x + ndx, y + ndy
                if 0 <= nx < N and 0 <= ny < N and not visit[nx][ny] and data[nx][ny] == 1:
                    q.append((nx, ny))
                    visit[nx][ny] = True
                    area += 1
        result.append(area)

result.sort()
print(len(result))
print(*result, sep='\n')