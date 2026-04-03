# 유형 : DFS (백트래킹!!!!)
from collections import deque

def solution(tickets):
    sorted_tickets = sorted(
        ((a, b, idx) for idx, (a, b) in enumerate(tickets)),
        key=lambda x: (x[0], x[1])
    )
    # print(sorted_tickets)
    
    n = len(sorted_tickets)
    path = ["ICN"]
    answer = []
    used = [False] * n
    def backtrack(cur, cnt):
        nonlocal answer, used
        
        if cnt == n:
            answer = path[:]
            return True
        
        for start, end, i in sorted_tickets:
            if used[i] or start != cur:
                continue
            
            used[i] = True
            path.append(end)
            if backtrack(end, cnt + 1):
                return
            path.pop()
            used[i] = False
            
        return False
    
    backtrack("ICN", 0)
    return answer