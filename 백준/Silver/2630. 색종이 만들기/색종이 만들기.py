"""
정사각형
BFS? 가 아니라 그냥 2중 for문 반복?
전체 종이가 모두 같은 색으로 칠해져 있지 않으면 4등분
- 모두 하얀색 또는 모두 파란색으로 칠해져 있거나, 하나의 정사각형 칸이 되어 더 이상 자를 수 없을 때까지 반복
출력 : 잘라진 하얀색 색종이와 파란색 색종이의 개수
"""

N = int(input())
data = [list(map(int, input().split())) for _ in range(N)]


def check(x, y, length): # 시작 좌표, 정사각형 크기
    global white, blue

    if length == 1:
        if data[x][y] == 0:
            white += 1
        else:
            blue += 1
        return
    
    # COLOR = { "WHITE", "BLUE", "ELSE" }
    color = 0 # 흰색 0 파란색 1
    for i in range(x, x + length):
        for j in range(y, y + length):
            color += data[i][j]
    
    if color == length * length: # 올블루
        blue += 1
    elif color == 0: # 올화이트
        white += 1
    else:
        half = int(length // 2)
        check(x, y, length//2)
        check(x + length//2, y, length//2)
        check(x, y + length//2, length//2)
        check(x + length//2, y + length//2, length//2)

white = 0
blue = 0
check(0, 0, N)
print(white)
print(blue)