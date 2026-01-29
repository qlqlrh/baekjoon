import sys
input = sys.stdin.readline

N, M = map(int, input().split())
d = dict()
d2 = dict()

for i in range(1, N + 1):
    name = input().rstrip()
    d[i] = name
    d2[name] = i

for _ in range(M):
    q = input().rstrip()
    if (q[0] in "0123456789"):
        print(d[int(q)])
    else:
        print(d2[q])