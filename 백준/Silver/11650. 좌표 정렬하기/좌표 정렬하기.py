import sys
input = sys.stdin.readline

N = int(input())

data = []
for _ in range(N):
    x, y = map(int, input().split())
    data.append((x, y))

data.sort(key=lambda coor: (coor[0], coor[1]))

sys.stdout.write('\n'.join(f"{x} {y}" for x, y in data))