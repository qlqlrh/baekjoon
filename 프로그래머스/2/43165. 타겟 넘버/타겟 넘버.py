def solution(numbers, target):
    answer = 0
    n = len(numbers)
    
    # 모든 number에 대해 부호 대입해 보기
    def backtrack(i, current_sum):
        nonlocal answer
        if i == n:
            if current_sum == target:
                answer += 1
            return
        
        backtrack(i + 1, current_sum + numbers[i])
        backtrack(i + 1, current_sum - numbers[i])
    
    backtrack(0, 0)
                
    return answer