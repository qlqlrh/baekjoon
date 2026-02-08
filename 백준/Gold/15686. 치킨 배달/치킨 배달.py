"""
칸 (r,c) : 빈 칸 0, 집 1, 치킨집 2
치킨거리 = 집과 가장 가까운 치킨집 사이의 거리
도시의 치킨거리 = 모든 집의 치킨 거리의 합
두 칸 사이의 거리 = |r1 - r2| + |c1 - c2|
출력 : M개의 치킨집을 선택했을 때, 도시의 최소 치킨거리
유형 : 조합 완전탐색
"""

import sys
from itertools import combinations

input = sys.stdin.readline
N, M = map(int, input().split())
data = [list(map(int, input().split())) for _ in range(N)]
# print(data)



""" 틀린 로직 (문제 이해 자체를 잘못함)
1. 각 집의 치킨거리 구하기
2. 내림차순 정렬
3. M개까지만 sum
"""
# dx = [1, -1, 0, 0]
# dy = [0, 0, 1, -1]

# MAX = 200
# min_dist = MAX
# dist = [[MAX] * N for i in range(N)]

# def bfs(x, y):
#     q = deque()
#     q.append((x, y))
#     vis = [[False] * N for _ in range(N)]
#     while q:
#         cx, cy = q.popleft()
#         # print("cx, cy", cx, cy)
#         for i in range(4):
#             nx, ny = cx + dx[i], cy + dy[i]
#             if nx >= N or nx < 0 or ny >= N or ny < 0:
#                 # print("경계")
#                 continue
#             if vis[nx][ny] == True or dist[nx][ny] != MAX:
#                 continue
#             if data[nx][ny] == 2:
#                 # print("abs", abs(x - nx), abs(y - ny))
#                 dist[nx][ny] = abs(x - nx) + abs(y - ny)
#                 return
#             q.append((nx, ny))
#             vis[nx][ny] = True

# for i in range(N):
#     for j in range(N):
#         if data[i][j] == 1:
#             # print("bfs", i, j)
#             bfs(i, j)

# dist_one = []
# for i in range(N):
#     for j in range(N):
#         dist_one.append(dist[i][j])

# dist_one.sort()
# print(dist_one)
# print(sum(dist_one[:M]))

"""
1. 치킨집 M개를 고르는 조합 구하기 (list)
2. 각 조합에 대한 도시의 치킨거리 구하기
3. 그 중 최솟값 출력
"""
chicken = []
house = []
for i in range(N):
    for j in range(N):
        if data[i][j] == 2:
            chicken.append((i, j))
        elif data[i][j] == 1:
            house.append((i, j))

chicken_com = list(combinations(chicken, M))
# print(chicken_com)

ans = 10**9
for com in chicken_com:
    sum_val = 0
    for h in house:
        min_dist = min(abs(h[0] - c[0]) + abs(h[1] - c[1]) for c in com)
        sum_val += min_dist
    ans = min(ans, sum_val)

print(ans)

