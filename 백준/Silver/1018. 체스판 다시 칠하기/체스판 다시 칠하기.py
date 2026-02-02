import sys
input = sys.stdin.readline

N, M = map(int, input().split())

"""
BFS (아닌 것 같음, 그냥 돌면 되는 것 같음) => 비트마스킹?
맨왼쪽 윗칸을 시작점으로 잡기
- i + 7, j + 7이 있어야 로직 시작
"""
dx = [-1,1,0,0]
dy = [0,0,-1,1]

data = []
for _ in range(N):
    temp = []
    for i in input().rstrip():
        temp.append(i)
    data.append(temp)

min_val = int(1e9)
for i in range(N):
    if i + 7 > N - 1:
        break
    for j in range(M):
        if j + 7 > M - 1:
            break
        for value in ["W", "B"]:
            val = value # 기준 값
            cnt = 0
            for ii in range(8):
                for jj in range(8):
                    if (ii % 2 == 0 and jj % 2 == 0) or (ii % 2 == 1 and jj % 2 == 1):
                        if data[i+ii][j+jj] != val:
                            cnt += 1
                    else:
                        if data[i+ii][j+jj] == val:
                            cnt += 1
            min_val = min(cnt, min_val)

print(min_val)