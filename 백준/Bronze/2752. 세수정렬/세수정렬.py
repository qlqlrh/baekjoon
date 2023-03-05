a, b, c = map(int, input().split())
d = 0

while (1):
    if a > b:
        d = b
        b = a
        a = d
    if b > c:
        d = c
        c = b
        b = d
    if a < b:
        break
    
print(a, b, c)