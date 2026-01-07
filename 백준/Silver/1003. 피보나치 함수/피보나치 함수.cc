#include <bits/stdc++.h>

using namespace std;

int one[42];
int zero[42];

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int T; // 테스트 케이스 개수
    cin >> T;

    // 초기값 세팅
    zero[0] = 1;
    zero[1] = 0;
    one[0] = 0;
    one[1] = 1;

    for (int i = 2; i <= 40; i++) {
        one[i] = one[i - 1] + one[i - 2];
        zero[i] = zero[i - 1] + zero[i - 2];
    }

    for (int i = 0; i < T; i++) {
        int n;
        cin >> n;

        cout << zero[n] << " " << one[n] << "\n";
    }
}