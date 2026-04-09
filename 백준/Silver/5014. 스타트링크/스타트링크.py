# 상태 BFS, 범위가 크므로, visited 배열 대신 set 활용

from collections import deque

# 전체 층수, 현재 위치, 목적지, 위로 U만큼 이동, 아래로 D만큼 이동
F, S, G, U, D = map(int, input().split())
cnt = 0 # 누른 총 버튼 수의 최솟값

visited = {S}
q = deque([(S, 0)]) # 현재 층수, 버튼 누른 횟수
while q:
    f, cost = q.popleft()
    if f == G: # 목적지 도착
        print(cost)
        exit(0)
        break

    if f + U <= F and f + U not in visited:
        q.append((f + U, cost + 1))
        visited.add(f + U)
    if f - D >= 1 and f - D not in visited:
        q.append((f - D, cost + 1))
        visited.add(f - D)

print("use the stairs")