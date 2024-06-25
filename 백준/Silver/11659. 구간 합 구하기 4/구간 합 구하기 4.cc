#include <iostream>
using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N; // 수의 개수
    int M; // 합을 구해야 하는 횟수
    cin >> N >> M;
    int sum[100001] = {}; // 0으로 세팅

    for (int i = 1; i <= N; i++) {
        int temp;
        cin >> temp;

        sum[i] = sum[i - 1] + temp; // 누적 합
    }

    for (int i = 0; i < M; i++) {
        int start, end;
        cin >> start >> end;

        cout << sum[end] - sum[start-1] << "\n";
    }
}