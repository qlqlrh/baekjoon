# BFS (그래프처럼 생각하고 접근해야 함)

from collections import deque

def solution(begin, target, words):
    answer = 0
    n = len(words)
    
    if target not in words:
        return 0

    q = deque([(begin, 0)])
    visit = set([begin])

    def diff(a, b):
        cnt = 0
        for aa, bb in zip(a, b):
            if aa != bb:
                cnt += 1
            if cnt >= 2:
                return False
        # for i in range(len(a)):
        #     if a[i] != b[i]:
        #         cnt += 1
        #     if cnt >= 2:
        #         return False
        return True

    while q:
        cw, dist = q.popleft()
        if cw == target:
            return dist
        for word in words:
            if word not in visit and diff(cw, word):
                q.append((word, dist + 1))
                visit.add(word)

    return answer