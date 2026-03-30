# 유형 : BFS
from collections import deque

def solution(maps):
    INF = 10 ** 9
    answer = 0
    n = len(maps)
    m = len(maps[0])
    
    dx = [1, -1, 0, 0]
    dy = [0, 0, 1, -1]
    dist = [[INF] * m for _ in range(n)]
    
    q = deque()
    q.append((0, 0))
    dist[0][0] = 1
    
    while q:
        row, col = q.popleft()
        
        for dir in range(4):
            nr, nc = row + dx[dir], col + dy[dir]
            
            if 0 > nr or nr >= n or 0 > nc or nc >= m:
                continue
            if maps[nr][nc] == 0:
                continue
            if dist[nr][nc] != INF:
                continue
    
            dist[nr][nc] = dist[row][col] + 1
            q.append((nr, nc))

            
    if dist[n-1][m-1] != INF:
        answer = dist[n-1][m-1]
    else:
        answer = -1
        
    return answer # 도착 못하면 -1, 상대에게 가는 칸의 최솟값