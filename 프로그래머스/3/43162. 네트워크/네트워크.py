from collections import deque
def solution(n, computers):
    answer = 0
    dx = [1,-1,0,0]
    dy = [0,0,1,-1]
    visit = [False] * n
    
    for i in range(n):
        if visit[i]:
            continue
        
        q = deque([(i)])
        visit[i] = True
        answer += 1
        
        while q:
            computer = q.popleft()
            for i in range(n):
                if not visit[i] and computers[computer][i]:
                    q.append(i)
                    visit[i] = True
    return answer