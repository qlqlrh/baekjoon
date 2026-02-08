"""
가능한 방향 저장해야 함
유형 : dp
dp[i][j][k] = 방향이 k인 상태에서 막대의 오른쪽 끝이 (i, j)일 때 가능한 경우의 수
prev = [0, 1, 2] : 0 가로, 1 세로, 2 대각
if 0 in prev: dp[i][j+1][0] += dp[i][j], dp[i+1][j+1] += dp[i][j]
if 1 in prev: dp[i+1][j] += dp[i][j], dp[i+1][j+1] += dp[i][j]
if 2 in prev: dp[i][j+1] += dp[i][j], dp[i+1][j] += dp[i][j], dp[i+1][j+1] += dp[i][j]
"""
import sys
input = sys.stdin.readline
N = int(input().rstrip())
data = [list(map(int, input().split())) for _ in range(N)] # 0-based

# dp[i][j][k]: (i,j)가 오른쪽 끝일 때 방향 k(0가로, 1세로, 2대각)인 경우의 수
dp = [[[0] * 3 for _ in range(N+1)] for _ in range(N+1)] # 1-based
dp[1][2][0] = 1

for i in range(1, N + 1):
    for j in range(2, N + 1):
        for k in range(3):
            if dp[i][j][k] != 0: # 해당 경로로 온 경우의 수가 존재
                if k == 0:
                    if j + 1 <= N and data[i-1][j] != 1:
                        dp[i][j+1][0] += dp[i][j][0] # 가로
                    if i + 1 <= N and j + 1 <= N and data[i][j] + data[i-1][j] + data[i][j-1] == 0:
                        dp[i+1][j+1][2] += dp[i][j][0] # 대각
                        # print("가로 => 대각", i, j, dp[i+1][j+1][2])
                elif k == 1:
                    if i + 1 <= N and data[i][j-1] != 1:
                        dp[i+1][j][1] += dp[i][j][1] # 세로
                    if i + 1 <= N and j + 1 <= N and data[i][j] + data[i-1][j] + data[i][j-1] == 0:
                        dp[i+1][j+1][2] += dp[i][j][1] # 대각
                elif k == 2:
                    if j + 1 <= N and data[i-1][j] != 1:
                        dp[i][j+1][0] += dp[i][j][2] # 가로
                    if i + 1 <= N and data[i][j-1] != 1:
                        dp[i+1][j][1] += dp[i][j][2] # 세로
                    if i + 1 <= N and j + 1 <= N and data[i][j] + data[i-1][j] + data[i][j-1] == 0:
                        dp[i+1][j+1][2] += dp[i][j][2] # 대각

print(dp[N][N][0] + dp[N][N][1] + dp[N][N][2])