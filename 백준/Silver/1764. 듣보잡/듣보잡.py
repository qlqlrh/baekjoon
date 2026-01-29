import sys
input = sys.stdin.readline

N, M = map(int, input().split())

no_see = set()
no_hear = set()

for _ in range(N):
    name = input().rstrip()
    no_see.add(name)
for _ in range(M):
    name = input().rstrip()
    no_hear.add(name)

result = no_see.intersection(no_hear)
result = list(result)
result.sort()

print(len(result))
sys.stdout.write("\n".join(result))