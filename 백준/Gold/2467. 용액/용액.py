"""
특성값 = 산성 값 + 알칼리값
특성값이 0에 가장 가까운 용액 만들기

알고리즘
- 완전 탐색? O(N^2)이라 안 될 듯
- 이분 탐색?
    - 0 - data[i] 한 값에 대해 bisect_left 하면
    - 해당 값을 0으로 만드는 가장 가까운 값 찾을 수 있을 듯?
    - 그렇게 찾은 값이랑 data[i] 더한 값 저장해놓고,
    - 그 중에 가장 0이랑 가까운 값 출력?
"""

from bisect import bisect_left, bisect_right

N = int(input())
data = list(map(int, input().split()))

result = []
for i in range(N):
    index = bisect_left(data, 0 - data[i])
    if index == N:
        index -= 1
    if index != 0 and abs(data[i] + data[index]) > abs(data[i] + data[index - 1]):
        index -= 1
    if (index != N - 1) and abs(data[i] + data[index]) > abs(data[i] + data[index + 1]):
        index += 1
    # print(data[i], data[index])
    if i != index:
        result.append((abs(0 - (data[i] + data[index])), data[i], data[index]))

result.sort()
# print(result)
if result[0][1] > result[0][2]:
    print(result[0][2], result[0][1])
else:
    print(result[0][1], result[0][2])