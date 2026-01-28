import sys
from collections import deque
input = sys.stdin.readline

N, K = map(int, input().split())
people = deque(range(1, N + 1))
result = []

while len(people) > 0:
    index = (K - 1) % len(people)
    result.append(people[index])
    people.remove(people[index])
    people.rotate(-index)

print("<", end='')
sys.stdout.write(", ".join(map(str, result)))
print(">")