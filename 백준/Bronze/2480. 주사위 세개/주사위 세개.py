dice = list(map(int, input().split()))
flag = [0] * 6
for i in dice:
    flag[i-1] += 1
for i in range(6):
    if flag[i] == 3:
        print(10000 + (i+1) * 1000)
        break
    elif flag[i] == 2:
        print(1000 + (i+1) * 100)
        break
    elif (flag[i] == 1) and (2 not in flag):
        print(int(max(dice)) * 100)
        break
