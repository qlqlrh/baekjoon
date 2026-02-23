"""
다음달에 선물 많이 받을 사람 예측

선물 지수 = 이번 달까지 자신이 친구들에게 준 선물의 수 - 받은 선물의 수
선물을 받는 경우 2가지
1. 선물 기록 존재 => 이번 달까지 두 사람 사이에 더 많은 선물을 준 사람이 다음 달에 선물을 하나++
2. 선물 기록 존재 x or 선물 횟수 같음 => 선물 지수가 더 큰 사람이 선물 지수가 더 작은 사람에게 선물을 하나++
    - 만약 두 사람의 선물 지수도 같다면 다음 달에 선물을 주고받지 않습니다.
"""
def solution(friends, gifts):
    answer = 0
    
    # 1. 모든 친구들에 대해서 두 사람 사이에 주고 받은 선물 기록 (준 회수) 저장
    n = len(friends)
    name_to_idx = {name: i for i, name in enumerate(friends)}
    table = [[0] * n for _ in range(n)]

    # 2. 모든 친구들에 대해서 선물 준 횟수, 받은 횟수 구하고,
    # 3. 사람별 선물 지수 구하기
    score = [0] * n
    for gift in gifts:
        giver, receiver = gift.split()
        gi, ri = name_to_idx[giver], name_to_idx[receiver]
        table[gi][ri] += 1
        score[gi] += 1
        score[ri] -= 1

    # 4. 결과 딕셔너리 생성
    result = [0] * n
    
    # 5-1. 친구 두 사람 사이에서 선물 기록 존재
    for i in range(n):
        for j in range(i + 1, n):
            # 준 횟수가 더 큰 사람 숫자 ++
            if table[i][j] > table[j][i]:
                result[i] += 1
            elif table[i][j] < table[j][i]:
                result[j] += 1
        # 5-2. 선물 기록 존재 X or 선물 횟수 같음
            elif table[i][j] == 0 or table[i][j] == table[j][i]:
                # 5-3. 선물 지수가 더 큰 사람 숫자 ++
                if score[i] < score[j]:
                    result[j] += 1
                elif score[i] > score[j]:
                    result[i] += 1
                # 5-4. 선물 기수가 같음
                else:
                    continue
    answer = max(result)
    return answer