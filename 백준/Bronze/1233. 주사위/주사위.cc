#include <iostream>
using namespace std;

int sum[81]; // 합 저장 (0으로 초기화)

int main() {
    int S1, S2, S3;
    cin >> S1 >> S2 >> S3;

    for (int i = 1; i <= S1; i++) {
        for (int j = 1; j <= S2; j++) {
            for (int k = 1; k <= S3; k++) {
                int s = i + j + k;
                sum[s] += 1;
            }
        }
    }

    int max = 0;
    int maxI = 0;
    for (int i = 80; i > 0; i--) { // ** 거꾸로 순회
        if (sum[i] >= max) {
            max = sum[i];
            maxI = i;
        }
        
    }
    cout << maxI << endl;

}
// **  답이 여러개라면 가장 합이 작은 것을 출력