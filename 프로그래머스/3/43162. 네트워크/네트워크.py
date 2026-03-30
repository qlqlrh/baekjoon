# 컴포넌트 개수 세기 (not 격자 BFS, Graph 문제!!)

from collections import deque

def solution(n, computers):
    answer = 0
    visit = [False] * n
    
    q = deque()
    for i in range(n):
        if visit[i]:
            continue
            
        q.append(i)
        visit[i] = True
        answer += 1
        
        while q:
            u = q.popleft()
            for v in range(n):
                if computers[u][v] == 1 and visit[v] == False:
                    visit[v] = True
                    q.append(v)
        
    return answer