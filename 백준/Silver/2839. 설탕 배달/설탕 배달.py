# 문제 : 2839
# 유형 : 그리디

import sys
input = sys.stdin.readline

N = int(input())
max_x = N // 3
max_y = N // 5

while max_y >= 0:
    remain = N - max_y * 5
    if remain % 3 == 0:
        print(max_y + remain // 3)
        exit(0)
    max_y -= 1

print("-1")