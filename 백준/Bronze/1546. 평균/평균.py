N = int(input())
score = list(map(int, input().split()))
max = max(score)
for i in range(N):
    score[i] = score[i] / max * 100
sum = 0
for i in score:
    sum += i
print(sum / N)