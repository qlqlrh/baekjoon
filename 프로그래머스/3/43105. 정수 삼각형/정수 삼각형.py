def solution(triangle):
    answer = 0
    # 각 위치에서 선택가능한 것 : 왼쪽 아래 or 오른쪽 아래
    # dp[i][j] : (i, j)에서 의 합의 최대
    # dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) => i-1 >= 0 and j-1 >= 0일 때
    
    dp = [[0] * len(row) for row in triangle]
    dp[0][0] = triangle[0][0]
    for i in range(1, len(triangle)):
        for j in range(len(triangle[i])): # 2, 3, 4, 5
            if j - 1 < 0:
                dp[i][j] = dp[i-1][j]
            elif j >= len(triangle[i]) - 1:
                dp[i][j] = dp[i-1][j-1]
            else:
                dp[i][j] = max(dp[i-1][j-1], dp[i-1][j])
            dp[i][j] += triangle[i][j]
                
    answer = max(dp[len(triangle) - 1])
    return answer