"""
반올림해서 소수 첫째자리까지 출력 round(area, 1)
다각형 면적 구하기
- 꼭짓점 좌표만으로 다각형 넒이를 한 번에 구하는 공식 존재
- 신발끈 공식
"""
N = int(input())
data = [list(map(int, input().split())) for _ in range(N)]
xlist = [coord[0] for coord in data]
ylist = [coord[1] for coord in data]

area = 0
for i in range(N):
    area += xlist[i] * ylist[(i + 1) % N]
    area -= xlist[i] * ylist[i - 1]

area = abs(area) * 0.5
area = float(round(area, 1))
print(area)
