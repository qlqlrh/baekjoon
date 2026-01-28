import sys
from collections import deque
input = sys.stdin.readline

N = int(input())
data = deque(i for i in range(1, N + 1))

while (len(data) > 1):
    data.popleft()
    num = data.popleft()
    data.append(num)

print(data[0])