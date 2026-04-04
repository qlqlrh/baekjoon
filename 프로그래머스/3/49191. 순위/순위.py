# 직접 승리 말고, 간접 승리까지 고려해야 함!!

def solution(n, results):
    win = [[False] * (n + 1) for _ in range(n + 1)]
    
    # 직접 승리
    for a, b in results:
        win[a][b] = True
    
    # 간접 승리
    for k in range(1, n + 1):
        for i in range(1, n + 1):
            for j in range(1, n + 1):
                if win[i][k] and win[k][j]:
                    win[i][j] = True
    
    # 순위 확정 가능한 사람 카운트
    answer = 0
    for i in range(1, n + 1):
        known = 0
        for j in range(1, n + 1):
            if i == j:
                continue
            if win[i][j] or win[j][i]:
                known += 1
        if known == n - 1:
            answer += 1
    
    return answer