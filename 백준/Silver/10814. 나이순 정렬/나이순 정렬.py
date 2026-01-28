import sys
input = sys.stdin.readline

# 정렬 (key에 따라, 우선순위에 따라)

N = int(input()) # 100,000 under
people = []
for _ in range(N):
    age, name = input().split()
    people.append((int(age), name))

people.sort(key=lambda x: x[0])

sys.stdout.write('\n'.join(f"{person[0]} {person[1]}" for person in people))
