import sys

input = sys.stdin.readline # 100,000 under
N = int(input())

data = []
for _ in range(N):
    data.append(int(input()))
data.sort()

sys.stdout.write('\n'.join(map(str, data)))