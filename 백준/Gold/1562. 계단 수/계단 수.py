# 계단수 : 인접한 모든 자리의 차이가 1인 수 (ex. 45656)
# 10개의 수 중에서 N개를 순서대로 뽑아야 함. 단, 제일 최근에 뽑은 수와 차이가 1인 수를 뽑아야 함. + 중복 가능
# 유형 : DP !!

MOD = 1_000_000_000
N = int(input())

# dp[길이][마지막 숫자][bitmask]
# dp[i][d][bitmask] : 길이가 i이고, 마지막 숫자가 d이고, 사용한 숫자가 bitmask인 경우의 수
dp = [[[0] * (1 << 10) for _ in range(10)] for _ in range(N + 1)]
for d in range(1, 10):
    dp[1][d][1 << d] = 1

for i in range(1, N):
    for d in range(10):
        for mask in range(1 << 10):
            if dp[i][d][mask] == 0:
                continue
            for nd in (d - 1, d + 1):
                if 0 <= nd <= 9:
                    nmask = mask | (1 << nd)
                    dp[i + 1][nd][nmask] += (dp[i][d][mask] % MOD)

FULL = (1 << 10) - 1
print(sum(dp[N][d][FULL] for d in range(10)) % MOD)