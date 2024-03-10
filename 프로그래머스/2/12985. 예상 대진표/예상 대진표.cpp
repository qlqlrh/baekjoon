#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 1;
    int preA = a;
    int preB = b;

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    while (true) {
        // 1. a, b의 다음 번호 구하기
        int nextA = (preA % 2 == 0) ? (preA / 2) : (preA / 2 + 1);
        int nextB = (preB % 2 == 0) ? (preB / 2) : (preB / 2 + 1);
        
        // 2. a, b의 번호가 같으면 그대로 종료
        if (nextA == nextB)
            break;
        
        // 2-1. a, b 번호가 다르면 라운드 수 추가
        answer += 1;
        
        // 3. a, b 값 업데이트
        preA = nextA;
        preB = nextB;
    }
    
    // cout << nextA << endl;
    
    return answer;
}