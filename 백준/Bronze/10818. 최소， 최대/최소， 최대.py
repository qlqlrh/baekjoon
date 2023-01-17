cnt = int(input())
num = list(map(int, input().split()))

min = num[0]
max = num[0]
i = 0
for i in range(cnt):
    if (num[i] < min):
        min = num[i]
    if (num[i] > max):
        max = num[i]

print(f'{min} {max}')