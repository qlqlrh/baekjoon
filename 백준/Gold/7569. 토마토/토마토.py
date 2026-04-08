# 확산? or 시작점이 여러개인 BFS?
# - 동시 확산 유형은 아닌 것 같은데, 동시 확산 유형은 어떤 거지?
# 출력 : 모든 토마토가 익는 최소 일수
from collections import deque

dir = [(1, 0, 0), (-1, 0, 0), (0, 1, 0), (0, -1, 0), (0, 0, 1), (0, 0, -1)]
M, N, H = map(int, input().split())
tomatos = [] # 1: 익은 토마토, 0 : 안 익은 토마토, -1: 빈칸
# print(tomatos)

for i in range(H):
    temp = []
    for j in range(N):
        inp = list(map(int, input().split()))
        temp.append(inp)
    tomatos.append(temp)

# 1인 좌표들 큐에 넣음
dist = [[[-1] * M for _ in range(N)] for _ in range(H)]
# print(dist)
q = deque()
flag = True

for i in range(H):
    for j in range(N):
        for k in range(M):
            if tomatos[i][j][k] == 1:
                q.append((i, j, k)) # x, y, z
                dist[i][j][k] = 0
            elif tomatos[i][j][k] == 0:
                flag = False

# 처음부터 다 익은 토마토뿐인 경우
if flag:
    print("0")
else:
    # bfs 돌림 (-1이면 확산 불가)
    while q:
        x, y, z = q.popleft()
        for ndx, ndy, ndz in dir:
            nx, ny, nz = x + ndx, y + ndy, z + ndz
            if 0 <= nx < H and 0 <= ny < N and 0 <= nz < M and dist[nx][ny][nz] == -1 and tomatos[nx][ny][nz] == 0:
                q.append((nx, ny, nz))
                dist[nx][ny][nz] = dist[x][y][z] + 1

    flag2 = False
    for i in range(H):
        for j in range(N):
            for k in range(M):
                if tomatos[i][j][k] == -1: # 원래 빈칸
                    continue
                if dist[i][j][k] == -1: # 빈칸이 아닌데 확산이 안 된 곳 존제
                    flag2 = True
                    break
    if flag2:
        print("-1")
    else:
        max_value = 0
        for floor in dist:
            for row in floor:
                for col in row:
                    max_value = max(max_value, col)
        print(max_value)