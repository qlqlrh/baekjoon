"""
정사각형
출력 : 지민이가 깔 수 잇는 가장 큰 돗자리의 한 변 길이
for, if문 이렇게 많은 게 맞나...?
"""
def solution(mats, park):
    answer = -1
    
    # 지민이가 가진 돗자리 넓이 만큼의 빈칸이 있는지 확인해야함
    for i in range(len(park)):
        for j in range(len(park[i])):
            if park[i][j] == "-1": # 검사 시작점
                for mat in mats: # 지민이가 가진 돗자리 길이
                    if (i + mat - 1 >= len(park)) or (j + mat - 1 >= len(park[i])): # 범위밖
                        continue
                        
                    flag = True
                    for x in range(i, i + mat):
                        for y in range(j, j + mat):
                            if park[x][y] != "-1":
                                flag = False
                                break
                        if not flag:
                            break
                    if flag:
                        answer = max(answer, mat)
    return answer