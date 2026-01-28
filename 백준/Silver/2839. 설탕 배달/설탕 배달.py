# 문제 : 2839
# 유형 : 브루트포스?

import sys
input = sys.stdin.readline

N = int(input())
max_x = N // 3
max_y = N // 5

INF = int(1e9)
min_value = INF
for i in range(max_x + 1):
    for j in range(max_y + 1):
        if (3 * i + 5 * j == N):
            if (i + j < min_value):
                min_value = i + j

if (min_value == INF):
    print("-1")
else:
    print(min_value)