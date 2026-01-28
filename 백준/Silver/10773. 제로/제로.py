import sys
from collections import deque
input = sys.stdin.readline

K = int(input())
#money = list(map(int, input()) for _ in range(K))

dq = deque()
for _ in range(K):
    money = int(input())
    if (len(dq) != 0) and (money == 0):
        dq.pop()
    elif money != 0:
        dq.append(money)

print(sum(dq))