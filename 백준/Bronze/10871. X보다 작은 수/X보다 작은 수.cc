#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N; // 수열 A의 길이
    int X; // 수열 A에서 판단 기준이 되는 수
    cin >> N >> X;

    int num;
    for (int i = 0; i < N; i++) {
        cin >> num;
        if (X > num) {
            cout << num << " ";
        }
    }
}