#include <bits/stdc++.h>

using namespace std;

// 문제 유형 : 그냥 구현? (확률과통계인듯;;)

int main() {
    int T; // 테스트 케이스 개수 (최대 100개)
    int N; // 해빈이가 가진 의상 수 (최대 30개)
    cin >> T;

    while (T--) {
        cin >> N;

        unordered_map<string, int> unmap;
        for (int i = 0; i < N; i++) {
            string name, type;
            cin >> name >> type;

            if (unmap.find(type) != unmap.end()) { // 이미 있는 옷 종류
                unmap[type]++;
            }
            else { // 처음 들어온 옷 종류
                unmap[type] = 1;
            }
        }

        int result = 1;
        for (auto it = unmap.begin(); it != unmap.end(); it++) {
            int num = (*it).second;
            result *= (num + 1);
        }

        cout << result - 1 << "\n";
    }
}