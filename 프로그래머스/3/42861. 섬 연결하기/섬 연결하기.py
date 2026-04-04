# 모든 노드 연결 + 최소 비용 => MST

def solution(n, costs):
    costs.sort(key=lambda x: x[2])
    parent = [i for i in range(n)]
    sizes = [1] * n
    cost = 0
    edge = 0
    
    def find(x):
        if parent[x] != x:
            parent[x] = find(parent[x])
        return parent[x]

    def union(aa, bb, cc):
        ra, rb = find(aa), find(bb)
        if ra == rb: # 루트가 같음 == 같은 컴포넌트 소속
            return False
        if ra < rb: # 루트번호가 더 큰 쪽으로 트리 합치기
            parent[ra] = rb
            sizes[rb] += sizes[ra]
        else:
            parent[rb] = ra
            sizes[ra] += sizes[rb]
        return True
    
    for a, b, c in costs:
        if union(a, b, c):
            cost += c
            edge += 1
        if edge == n - 1:
            break

    return cost