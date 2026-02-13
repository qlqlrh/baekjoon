"""
[구현문제]
꺼내야 하는 상자 개수 출력
%w 사용하면 될 듯 한데
아니다. 쌓는 방향이 왼오 오왼으로 달라지니까, 2차원 배열 만들어야 할 듯
1. 1~n까지의 수 w개씩 나눠서 2차원 배열 생성 (box)
2. num은 몇 번째 인덱스인지 확인 (i, j)
3. box에서 i 이상에서 j번째 인덱스 가지고 있는 것만큼 개수 출력
"""

def solution(n, w, num):
    answer = 0
    box = []
    temp = []
    xy = (0, 0)
    
    # 1. 2차원 배열 생성
    for i in range(1, n + 1):
        temp.append(i)
        if len(temp) == w:
            box.append(temp)
            temp = []
    if temp:
        box.append(temp)

    for i in range(len(box)):
        if len(box[i]) != w:
            while len(box[i]) != w:
                box[i].append(-1)
        if i % 2: # odd
            box[i].reverse()
    
    # 2. num은 몇 번째 인덱스인지 확인 (i, j)
    for i in range(len(box)):
        for j in range(len(box[i])):
            if box[i][j] == num:
                xy = (i, j)

    # print(box)
    # print(xy)
        
    # 3. box에서 i 이상에서 j번째 인덱스 값이 -1이 아니면 answer++
    for i in range(xy[0], len(box)):
        if box[i][xy[1]] != -1:
            answer += 1

    return answer