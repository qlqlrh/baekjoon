# BFS (격자X, 그래프)
from collections import deque

def solution(n, computers):
    answer = 0
    visit = [False] * n
    
    for i in range(n):
        if visit[i]:
            continue
        if computers[i] == 0:
            continue
        q = deque([i])
        visit[i] = True
        
        while q:
            u = q.pop()
            for v in range(n):
                if visit[v] != True and computers[u][v]:
                    q.append(v)
                    visit[v] = True
        answer += 1

    return answer