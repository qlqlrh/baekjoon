#include <iostream>
#include <limits>
#include <string>
#define INF numeric_limits<int>::max();
using namespace std;

int N, M; // 체스판 가로, 세로 크기
char chess[51][51];
string WB = "WBWBWBWBBWBWBWBWWBWBWBWBBWBWBWBWWBWBWBWBBWBWBWBWWBWBWBWBBWBWBWBW"; // ** 정답 형태
string BW = "BWBWBWBWWBWBWBWBBWBWBWBWWBWBWBWBBWBWBWBWWBWBWBWBBWBWBWBWWBWBWBWB";

int calRepaintB(int x, int y) { // 가로 끝, 세로 끝
    int cnt = 0;
    int k = 0;
    for (int i = x - 7; i <= x; i++)
        for (int j = y - 7; j <= y; j++)
            if (chess[i][j] != BW[k++])
                cnt++;
    return cnt;
}

int calRepaintW(int x, int y) { // 가로 끝, 세로 끝
    int cnt = 0;
    int k = 0;
    for (int i = x - 7; i <= x; i++)
        for (int j = y - 7; j <= y; j++)
            if (chess[i][j] != WB[k++])
                cnt++;
    return cnt;
}

int main() {

    // 1. 입력 받기
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++)
            cin >> chess[i][j];
    }

    if (N == 8 && M == 8)
        cout << min(calRepaintB(8, 8), calRepaintW(8, 8)) << endl;
    else {
        int minVal = INF;
        for (int i = 8; i <= N; i++) {
            for (int j = 8; j <= M; j++) {
                int num = min(calRepaintB(i, j), calRepaintW(i, j));
                if (minVal > num)
                    minVal = num;
            }
        }
        cout << minVal << endl;
    }
}

// ** 정답의 형태가 딱 2개로 정해져 있음
// ** 앞 뒤 문자를 하나하나 비교하는 것보다, 정답과 같다/다르다로 비교하는 게 훨씬 효율 good