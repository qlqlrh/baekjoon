#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N; // 재료의 개수 (1 <= N <= 15,000)
    int M; // 갑옷을 만드는 데 필요한 수 (1 <= M <= 10,000,000)
    
    cin >> N;
    cin >> M;

    vector<int> material(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> material[i];
    }

    sort(material.begin(), material.end());

    int begin = 0;
    int end = N - 1;
    int cnt = 0;

    while (begin < end) {
        int sum = material[begin] + material[end];
        if (sum == M) {
            cnt++;
            begin++;
            end--;
        }
        else if (sum < M) {
            begin++;
        }
        else {
            end--;
        }
    }

    cout << cnt << "\n";
    return 0;
}
