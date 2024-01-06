#include <iostream>
using namespace std;

int N; // 색종이 개수
bool paper[100][100]; // 도화지 (0으로 초기화)

int main() {

    // 1, 2, 3번을 동시에
    cin >> N;
    int x, y;
    int sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        for (int j = x; j < (x + 10); j++) {
            for (int k = y; k < (y + 10); k++) {
                if (paper[j][k] != 1) {
                    paper[j][k] = 1;
                    sum += 1;
                }
            }
        }

    }

    // 4. 출력
    cout << sum;
}