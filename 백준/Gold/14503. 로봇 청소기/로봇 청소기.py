# visit에 방향 상태 추가 [x][y][d]
from collections import deque

N, M = map(int, input().split())
rr, rc, rd = map(int, input().split()) # 0-indexed
if rd == 1:
    rd = 3
elif rd == 3:
    rd = 1

# 1 : 벽, 0 : 청소되지 않은 빈칸
room = [[] for _ in range(N)]
for i in range(N):
    inp = list(map(int, input().split()))
    room[i] = inp

visited = [[[False] * 4 for _ in range(M)] for _ in range(N)]
dirs = [(-1,0), (0,-1), (1,0), (0,1)] # 북 서 남 동
result = 0 if room[rr][rc] else 1 # 청소한 칸의 개수

q = deque([(rr, rc, rd)])
visited[rr][rc][rd] = True

while q:
    x, y, d = q.popleft()
    no_room = True

    # 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 있는 경우
    for i in range(1, 5):
        nd = (d + i) % 4
        nx, ny = x + dirs[nd][0], y + dirs[nd][1]
        if 0 <= nx < N and 0 <= ny < M and not any(visited[nx][ny]) and room[nx][ny] == 0:
            # print("청소 완료")
            q.append((nx, ny, nd))
            visited[nx][ny][nd] = True
            no_room = False
            # print(nx, ny, nd)
            result += 1
            break

    # 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 없는 경우
    if no_room:
        nx, ny = x - dirs[d][0], y - dirs[d][1]
        if 0 <= nx < N and 0 <= ny < M and room[nx][ny] == 0:
            q.append((nx, ny, d))
            visited[nx][ny][d] = True
        if 0 <= nx < N and 0 <= ny < M and room[nx][ny] == 1:
            print(result)
            exit(0)

print(result)