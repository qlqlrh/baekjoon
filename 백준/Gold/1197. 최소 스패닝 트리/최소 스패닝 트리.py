# 무방향 그래프

import sys
sys.setrecursionlimit(10 ** 6)

def find(x):
    if parent[x] != x:
        x = find(parent[x])
    return x


def union(a, b):
    ra, rb = find(a), find(b)
    if ra == rb:
        return False
    
    if size[ra] > size[rb]:
        parent[rb] = ra
        size[ra] += size[rb]
    else:
        parent[ra] = rb
        size[rb] += size[ra]
    
    return True

V, E = map(int, input().split())
graph = []
for _ in range(E):
    inp = list(map(int, input().split()))
    graph.append(inp)

graph.sort(key=lambda x: x[2])
parent = list(range(V + 1))
# print(parent)
# print(graph)
size = [1] * (V + 1)

w_total = 0
e_cnt = 0

for u, v, e in graph:
    # print(u, v, e)
    if union(u, v):
        w_total += e
        e_cnt += 1
    if e_cnt == V - 1:
        break

print(w_total)