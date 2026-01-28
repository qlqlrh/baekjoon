import sys

for line in sys.stdin:
    a, b, c = sorted(map(int, line.split()))

    if (a == 0 and b == 0 and c == 0):
        break
    if (a * a + b * b == c * c):
        print("right")
    else:
        print("wrong")