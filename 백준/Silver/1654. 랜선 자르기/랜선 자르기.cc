#include <iostream>

using namespace std;

int K; // 이미 가지고 있는 랜선의 개수
int N; // 필요한 랜선의 개수

/**
 * point !
 * 이진 탐색으로 잘라낼 랜선의 길이를 구해야 함
 * 따라서 시간복잡도는 O(N)
 */

int main() {    

    std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

    cin >> K >> N;

    long long lengths[K];
    long long maxLength = 0;
    long long minLength = 1;
    for (int i = 0; i < K; i++) {
        cin >> lengths[i];
        if (maxLength < lengths[i]) {
            maxLength = lengths[i];
        }
    }

    long long result = 0;
    while (minLength <= maxLength) {
        long long midLength = (minLength + maxLength) / 2; // 중간값
        int cnt = 0; // 랜선의 개수
        for (int i = 0; i < K; i++) {
            cnt += (lengths[i] / midLength);
        }
        if (cnt >= N) {
            minLength = midLength + 1;
            result = midLength;
        }
        else if (cnt < N) { // 랜선의 길이가 더 짧아야 함
            maxLength = midLength - 1; // -1을 해줘야 함!
        }
    }

    cout << result << endl;

}