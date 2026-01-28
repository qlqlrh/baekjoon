import sys

while True:
    a, b, c = map(int, input().split())
    
    if (a == 0 and b == 0 and c == 0):
        break

    list = [a, b, c]
    list.sort()
    if (list[0] * list[0] + list[1] * list[1] == list[2] * list[2]):
        print("right")
    else:
        print("wrong")