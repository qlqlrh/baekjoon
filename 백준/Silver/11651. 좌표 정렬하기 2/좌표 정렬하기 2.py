import sys
input = sys.stdin.readline

N = int(input())
data = [tuple(map(int, input().split())) for _ in range(N)]
data.sort(key=lambda coord: (coord[1], coord[0]))

sys.stdout.write('\n'.join(f"{x} {y}" for x, y in data))
