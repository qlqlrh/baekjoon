# 양방향 그래프 BFS

from collections import deque, defaultdict
def solution(n, edge):
    answer = 0
    visit = [False] * (n + 1)
    dist = [-1] * (n + 1) # dist[i] : 1과 i 사이의 최소 거리
    
    graph = defaultdict(list)
    for a, b in edge:
        graph[a].append(b)
        graph[b].append(a)
            
    q = deque([1])
    visit[1] = True
    dist[1] = 0
    
    while q:
        num = q.popleft()
        for node in graph[num]:
            if visit[node]:
                continue
            visit[node] = True
            q.append(node)
            dist[node] = dist[num] + 1        
    
    max_value = max(dist)
    for num in dist:
        if num == max_value:
            answer += 1
    
    return answer
