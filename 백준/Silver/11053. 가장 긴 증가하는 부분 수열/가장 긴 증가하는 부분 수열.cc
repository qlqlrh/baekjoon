#include <bits/stdc++.h>

using namespace std;

// 유형 : DP

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N; // 1000 under
    cin >> N;

    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i]; // 1000 under
    }

    vector<int> D(N, 1);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (v[j] < v[i]) {
                D[i] = max(D[i], D[j] + 1);
            }
        }
    }

    cout << *max_element(D.begin(), D.end()) << "\n";
}