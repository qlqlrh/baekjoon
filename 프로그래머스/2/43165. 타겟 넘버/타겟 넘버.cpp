#include <bits/stdc++.h>

using namespace std;

int answer = 0;

void backtrack(int start, int cnt, const vector<int>& numbers, int target) {
    if (start == numbers.size()) {
        if (cnt == target) {
            answer++;
        }
        return;
    }

    backtrack(start + 1, cnt + numbers[start], numbers, target);
    backtrack(start + 1, cnt - numbers[start], numbers, target);
}

int solution(vector<int> numbers, int target) {

    backtrack(0, 0, numbers, target);
    
    return answer;
}