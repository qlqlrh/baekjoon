"""
구현 문제
출력: 지갑에 넣기 위해 지폐를 접어야 하는 최소 횟수
"""

def solution(wallet, bill):
    answer = 0
    ww, wl = wallet
    bw, bl = bill
    
    while (min(bw, bl) > min(ww, wl)) or (max(bw, bl) > max(ww, wl)):
        if max(bw, bl) == bw:
            bw //= 2
        else:
            bl //= 2
        answer += 1
    return answer