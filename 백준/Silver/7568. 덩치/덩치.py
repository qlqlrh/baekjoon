import sys
from itertools import combinations
input = sys.stdin.readline

# (x, y) = (몸무게, 키)
N = int(input())
li = [tuple(map(int, input().split())) for _ in range(N)]

result = dict()
for i in range(N):
    result[i] = 1

for i in range(N):
    for j in range(i + 1, N):
        if (li[i][0] < li[j][0] and li[i][1] < li[j][1]):
            result[i] += 1
        elif (li[i][0] > li[j][0] and li[i][1] > li[j][1]):
            result[j] += 1

sys.stdout.write(' '.join(map(str, (result[i] for i in range(N)))) + '\n')

