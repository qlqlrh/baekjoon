import sys
from collections import deque
input = sys.stdin.readline

N, M = map(int, input().split())

# 백트래킹
result = deque() # 백터처럼 사용

def backtrack():
    if len(result) == M:
        sys.stdout.write(" ".join(map(str, result)) + "\n")
        return
    
    for i in range(1, N + 1):
        if i in result:
            continue
        result.append(i)
        backtrack()
        result.pop()
    return

backtrack()