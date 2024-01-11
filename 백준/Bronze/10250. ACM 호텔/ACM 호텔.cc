#include <stdio.h>
using namespace std;

// * 엘베에서 가까운 방 선호
// * 거리가 같으면 아래층 방 선호
// * 2차원 배열 쓰면 될 듯?

int main() {
    int T;       // 테스트케이스 개수
    int H, W, N; // 호텔 층, 각 층의 방 수, 몇 번째 손님

    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        scanf("%d %d %d", &H, &W, &N);

        int room = 1;
        while (N > H) {
            N -= H;
            room += 1;
        }
        printf("%d%02d\n", N, room);
    }
}