import sys
input = sys.stdin.readline

M = int(input())
s = set()

for _ in range(M):
    command = input().split()
    if command[0] == "add":
        num = int(command[1])
        s.add(num)
    elif command[0] == "remove":
        num = int(command[1])
        s.discard(num)
    elif command[0] == "check":
        num = int(command[1])
        if num in s:
            print("1")
        else:
            print("0")
    elif command[0] == "toggle":
        num = int(command[1])
        if num in s:
            s.remove(num)
        else:
            s.add(num)
    elif command[0] == "all":
        s = set(range(1, 21))
    elif command[0] == "empty":
        s = set()