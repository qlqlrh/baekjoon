#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N; // 줄을 선 사람 명 수
    cin >> N;

    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    int sum = 0;
    int preSum = 0;
    for (int i = 0; i < N; i++) {
        preSum += v[i];
        sum += preSum;
    }

    cout << sum << "\n";
}