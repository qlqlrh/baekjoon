def solution(players, callings):
    answer = players

    # 선수이름 -> 인덱스 매핑한 딕셔너리 생성 (dict, enumerate)
    name_to_idx = {name: i for i, name in enumerate(players)}

    # callings 순서대로 swap
    for calling in callings:
        ci = name_to_idx[calling]
        answer[ci - 1], answer[ci] = answer[ci], answer[ci - 1]
        name_to_idx[answer[ci - 1]], name_to_idx[answer[ci]] = name_to_idx[answer[ci]], name_to_idx[answer[ci - 1]]

    return answer