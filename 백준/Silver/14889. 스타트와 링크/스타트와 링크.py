import sys
from itertools import combinations

input = sys.stdin.readline

N = int(input())
S = [list(map(int, input().split())) for _ in range(N)]

result = 10 ** 9

for start in combinations(range(1, N + 1), N // 2):
    link = [i for i in range(1, N + 1) if i not in start]
    
    s = 0
    l = 0
    for i in start:
        for j in start:
            if i != j:
                s += S[i - 1][j - 1]
    for i in link:
        for j in link:
            if i != j:
                l += S[i - 1][j - 1]
    result = min(result, abs(s - l))

print(result)