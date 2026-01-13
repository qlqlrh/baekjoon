#define justPrint(x) cout << x << "\n";
#define listPrint(x) for (auto i : x) cout << i << " "; cout << "\n";

#include <bits/stdc++.h>

// 자연수 N과 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.
// 1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열
// 고른 수열은 오름차순이어야 한다.

using namespace std;
int N, M; // 1 <= M <= N <= 8
vector<int> result;

void backtrack(int start) {
    // 기저 조건: M개를 모두 선택했으면 출력
    if (result.size() == M) {
        listPrint(result);
        return;
    }
    
    // start부터 N까지 숫자를 선택
    for (int i = start; i <= N; i++) {
        result.push_back(i);      // 선택
        backtrack(i + 1);         // 다음 숫자는 현재보다 큰 수부터 (오름차순 보장)
        result.pop_back();        // 백트래킹: 선택 취소
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    cin >> N >> M;
    
    backtrack(1);  // 1부터 시작
    
    return 0;
}