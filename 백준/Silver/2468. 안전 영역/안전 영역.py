# 컴포넌트 개수
# 출력 : 물에 안 잠기는 안전 영역 최대 개수 출력

from collections import deque

N = int(input())
data = [[] for _ in range(N)]
for i in range(N):
    inp = list(map(int, input().split()))
    data[i] = inp

# BFS 여러번 돌리면서, 최대 개수 찾아야 될 듯
# 최대, 최소 값 구하기
INF = float('inf')
max_value = 0
min_value = 101
for row in data:
    for col in row:
        max_value = max(max_value, col)
        min_value = min(min_value, col)

result = 0
for k in range(max_value):
    visited = [[False] * N for _ in range(N)]
    cnt = 0
    for i in range(N):
        for j in range(N):
            if visited[i][j] or data[i][j] <= k: # 이미 방문했거나, 물에 잠기는 부분이면 제외
                continue
            q = deque([(i, j)])
            visited[i][j] = True
            cnt += 1

            while q:
                x, y = q.popleft()
                for ndx, ndy in [(1,0), (-1,0), (0,1), (0,-1)]:
                    nx, ny = x + ndx, y + ndy
                    if 0 <= nx < N and 0 <= ny < N and not visited[nx][ny] and data[nx][ny] > k:
                        q.append((nx, ny))
                        visited[nx][ny] = True
    result = max(result, cnt)
print(result)