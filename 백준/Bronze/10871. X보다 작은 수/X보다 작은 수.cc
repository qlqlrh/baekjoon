#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N; // 수열 A의 길이
    int X; // 수열 A에서 판단 기준이 되는 수
    vector<int> a(N);

    cin >> N >> X;

    for (int i = 0; i < N; i++) {
        cin >> a[i];
        if (X > a[i]) {
            cout << a[i] << " ";
        }
    }
}