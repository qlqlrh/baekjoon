import sys
input = sys.stdin.readline

def recur(remain):
    global cnt
    for i in range(N-1, -1, -1):
        if (A[i] <= remain):
            max_val = A[i]
            q = remain // max_val
            cnt += q
            break;
    left = remain - q * max_val
    
    if left == 0:
        return
    else:
        recur(left)

N, K = map(int, input().split())
A = [int(input().rstrip()) for _ in range(N)]

cnt = 0
recur(K)

print(cnt)