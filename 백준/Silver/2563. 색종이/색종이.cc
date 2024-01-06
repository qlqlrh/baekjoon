#include <iostream>
using namespace std;

int N; // 색종이 개수
bool paper[101][101]; // 도화지 (0으로 초기화)

int main() {

    // 1. 입력 받기
    cin >> N;
    int coor[N][2]; // * VS에서는 사이즈 설정할 때 변수가 들어가면 에러뜸
    for (int i = 0; i < N; i++) {
        cin >> coor[i][0] >> coor[i][1];
    }

    // 2. 색종이의 넓이를 좌표에 표시
    for (int i = 0; i < N; i++) {
        int x = coor[i][0];
        int y = coor[i][1];
        for (int j = x; j < (x + 10); j++) {
            for (int k = y; k < (y + 10); k++) {
                paper[j][k] = 1;
            }
        }
    }

    // 3. 면적 합 구하기
    int sum = 0;
    for (int i = 1; i <= 100; i++) {
        for (int j = 1; j <= 100; j++) {
            if (paper[i][j] == 1)
                sum += 1;
        }
    }

    // 4. 출력
    cout << sum;
}